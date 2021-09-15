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
    internal class CopyEntireDir
    {
        public void copyEntireDir(string sourcePath, string destPath)
        {
            foreach (string dirPath in Directory.GetDirectories(sourcePath, "*",
               SearchOption.AllDirectories))
                Directory.CreateDirectory(dirPath.Replace(sourcePath, destPath));

            foreach (string newPath in Directory.GetFiles(sourcePath, "*.*",
               SearchOption.AllDirectories))
                File.Copy(newPath, newPath.Replace(sourcePath, destPath), true);
        }
    }
}