using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using XDevkit;
using JRPC_Client;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        IXboxConsole xbox;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(xbox.Connect(out xbox))
            {
                xbox.XNotify("yes");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        public uint WriteEmbPointer(uint empointer)
        {
            return xbox.ReadUInt32(empointer) + 0xFB5C;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Title = "Select your Custom Thumbnail file to Inject to Black Ops II...";
            openFileDialog.Filter = "Gsc|*.gsc|BIN|*.bin|All Files|*.*";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                byte[] array = File.ReadAllBytes(openFileDialog.InitialDirectory + openFileDialog.FileName);
                array.Reverse();

                MessageBox.Show("Infection INJECTED!", "Injected.", MessageBoxButtons.OK);

                xbox.SetMemory(1076887552, array);//0x831EBE78
                xbox.WriteInt32(2199830136U, 1076887552);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Title = "Save ";
            saveFileDialog.Filter = "BIN|*.bin";
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                uint address = xbox.ReadUInt32(2199830136);
                xbox.GetMemory(address, 0xFB5B);
                File.WriteAllBytes(saveFileDialog.InitialDirectory + saveFileDialog.FileName, xbox.GetMemory(address, 0xFB5B));
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Title = "Select your Custom Thumbnail file to Inject to Black Ops II...";
            openFileDialog.Filter = "JPG|*.jpg|BIN|*.bin|All Files|*.*";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                byte[] array = File.ReadAllBytes(openFileDialog.InitialDirectory + openFileDialog.FileName);
                array.Reverse<byte>();
                MessageBox.Show("Custom Thumbnail INJECTED!", "Injected.", MessageBoxButtons.OK);
                uint address = xbox.ReadUInt32(2199830136);
                xbox.SetMemory(address, array);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        
        private void button5_Click(object sender, EventArgs e)
        {
            xbox.WriteString(0x83BD0678 + 0xE, textBox1.Text);
        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            xbox.WriteString(0x83BD0678 + 0x4F, textBox2.Text);
        }
    }
}
