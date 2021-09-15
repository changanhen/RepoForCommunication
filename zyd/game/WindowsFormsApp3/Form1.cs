using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if (!Directory.Exists("D:\\小丑竟是你自己"))
            {
                Directory.CreateDirectory("D:\\小丑竟是你自己");
                Directory.CreateDirectory("D:\\小丑竟是你自己\\小丑竟是你自己");
            }
            if (!File.Exists("D:\\小丑竟是你自己\\小丑竟是你自己\\小丑竟是你自己.txt"))
            {
                FileStream fs1 = new FileStream("D:\\小丑竟是你自己\\小丑竟是你自己\\小丑竟是你自己.txt", FileMode.Create, FileAccess.Write);
                File.SetAttributes(@"D:\\小丑竟是你自己\\小丑竟是你自己\\小丑竟是你自己.txt", FileAttributes.Hidden);
                StreamWriter sw = new StreamWriter(fs1);
                sw.WriteLine("哈哈哈哈，被你发现了！");
                sw.WriteLine("哥可是有几个分身的【doge】");
                sw.Flush();
                CopyEntireDir copy = new CopyEntireDir();
                string sourcePath = "D:\\小丑竟是你自己";
                string destPath = "C:\\小丑竟是你自己";
                copy.copyEntireDir(sourcePath, destPath);
            }


        }

        protected override void OnClosing(CancelEventArgs e)
        {
            DialogResult result = MessageBox.Show("在看看嘛[doge]", "警告",
                                  MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            e.Cancel = result != DialogResult.Yes;
            base.OnClosing(e);
        }


        private void label3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("你触碰了不该触碰的东西！", "警告", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
    }
}
