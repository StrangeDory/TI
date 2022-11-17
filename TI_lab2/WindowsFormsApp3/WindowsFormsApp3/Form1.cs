using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        readonly int registerSize = 24;

        byte ConvertByte(BitArray bits)
        {
            byte[] bytes = new byte[1];
            bits.CopyTo(bytes, 0);
            return bytes[0];
        }

        private void Encrypt_Click(object sender, EventArgs e)
        {
            string path_txt = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\зашифрованный вид.txt";
            string path_encrypt = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\encrypted_";
            var initialState = initState.Text;
            var lentext1 = initialState.Length;
            textBoxResult.Text = "";
            labelKey.Text = "";
            for (int i = 0; i < lentext1; i++)
            {
                if (initialState[i] != '1' && initialState[i] != '0')
                {
                    initialState = initialState.Remove(i, 1);
                    lentext1--;
                    i--;
                }
            }
            if (lentext1 < registerSize)
            {
                MessageBox.Show(this, "Длина начального состояния должна быть равна 24!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                initState.Text = "111111111111111111111111";
                return;
            }
            if (lentext1 > registerSize)
                initialState = initialState.Remove(registerSize, lentext1 - registerSize);

            var lfsr1 = new int[registerSize];
            for (int i = 0; i < registerSize; i++)
            {
                lfsr1[i] = Convert.ToInt32(Convert.ToString(initialState[i]));
            }
            string key = "";
            string result = "";
            bool isContinue = true;
            int index = 0;
            void Print()
            {
                for (index = 0; index < bytes.Length; index++)
                {
                    Invoke(new Action(() => labelKey.AppendText(isContinue && key.Length != 0 ? Convert.ToString(key[index]) : "")));
                    Invoke(new Action(() => textBoxResult.AppendText(isContinue && key.Length != 0 ? Convert.ToString(result[index]) : "")));
                }
            }
            Thread thread = new Thread(Print);
            thread.IsBackground = true;
            thread.Start();

            for (int i = 0; i < bytes.Length; i++)
            {
                Application.DoEvents();
                key += Convert.ToString(lfsr1[0]);

                int xor = lfsr1[0] ^ lfsr1[20] ^ lfsr1[21] ^ lfsr1[23];


                for (int q = 0; q < registerSize - 1; q++)
                {
                    lfsr1[q] = lfsr1[q + 1];

                }
                lfsr1[23] = xor;
                int a = Convert.ToInt32(Convert.ToString(key[i]));
                int b = Convert.ToInt32(Convert.ToString(bytes[i]));
                int Xor = a ^ b;
                result += Xor;
            }

            File.WriteAllText(path_txt, result);
            using (BinaryWriter writerbin1 = new BinaryWriter(File.Create(path_encrypt + fileName)))
            {
                int j = 0;
                bool[] arr = new bool[8];
                for (int i = 0; i < bytes.Length; i++)
                {
                    bool buf1, buf2;
                    buf1 = bytes[i] == '1';
                    buf2 = key[i] == '1';
                    arr[i % 8] = (buf1 ^ buf2);
                    j++;
                    if (j == 8)
                    {
                        BitArray bitarray = new BitArray(new bool[] { arr[7], arr[6], arr[5], arr[4], arr[3], arr[2], arr[1], arr[0] });
                        byte n = ConvertByte(bitarray);
                        j = 0;
                        writerbin1.Write(n);
                    }
                }
            }
            isContinue = false;
            thread.Abort();
            thread.Join();
            if (bytes.Length > index+1)
            {
                labelKey.AppendText(key.Substring(index + 1));
                textBoxResult.AppendText(result.Substring(index + 1));
            }

        }

        string bytes = "";
        string fileName;
        private void Decrypt_Click(object sender, EventArgs e)
        {
            string path_txt = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\расшифрованный вид.txt";
            string path_decrypt = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\decrypted_";
            var initialState = initState.Text;
            var lentext1 = initialState.Length;
            textBoxResult.Text = "";
            labelKey.Text = "";
            for (int i = 0; i < lentext1; i++)
            {
                if (initialState[i] != '1' && initialState[i] != '0')
                {
                    initialState = initialState.Remove(i, 1);
                    lentext1--;
                    i--;
                }
            }
            if (lentext1 < registerSize)
            {
                MessageBox.Show(this, "Длина начального состояния должна быть равна 24!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                initState.Text = "111111111111111111111111";
                return;
            }
            if (lentext1 > registerSize)
                initialState = initialState.Remove(registerSize, lentext1 - registerSize);

            var lfsr1 = new int[registerSize];
            for (int i = 0; i < registerSize; i++)
            {
                lfsr1[i] = Convert.ToInt32(Convert.ToString(initialState[i]));
            }

            string key = "";
            string result = "";
            bool isContinue = true;
            int index = 0;
            void Print()
            {
                for (index = 0; index < bytes.Length; index++)
                {
                    Invoke(new Action(() => labelKey.AppendText(isContinue ? Convert.ToString(key[index]) : "")));
                    Invoke(new Action(() => textBoxResult.AppendText(isContinue ? Convert.ToString(result[index]) : "")));
                }
            }

            Thread thread = new Thread(Print);
            thread.IsBackground = true;
            thread.Start();
            for (int i = 0; i < bytes.Length; i++)
            {
                key += Convert.ToString(lfsr1[0]);
                int xor = lfsr1[0] ^ lfsr1[20] ^ lfsr1[21] ^ lfsr1[23];


                for (int q = 0; q < registerSize-1; q++)
                {
                    lfsr1[q] = lfsr1[q + 1];

                }
                lfsr1[23] = xor;
                int a = Convert.ToInt32(Convert.ToString(key[i]));
                int b = Convert.ToInt32(Convert.ToString(bytes[i]));
                int Xor = a ^ b;
                result += Xor;
            }


            File.WriteAllText(path_txt, result);
            using (BinaryWriter writerbin2 = new BinaryWriter(File.Create(path_decrypt + fileName)))
            {
                int j = 0;
                bool[] arr = new bool[8];
                for (int i = 0; i < bytes.Length; i++)
                {
                    bool buf1, buf2;
                    buf1 = bytes[i] == '1';
                    buf2 = key[i] == '1';
                    arr[i % 8] = (buf1 ^ buf2);
                    j++;
                    if (j == 8)
                    {
                        BitArray bitarray = new BitArray(new bool[] { arr[7], arr[6], arr[5], arr[4], arr[3], arr[2], arr[1], arr[0] });
                        byte n = ConvertByte(bitarray);
                        j = 0;
                        writerbin2.Write(n);
                    }
                }
            }
            isContinue = false;
            thread.Abort();
            thread.Join();
            if (bytes.Length > index + 1)
            {
                labelKey.AppendText(key.Substring(index + 1));
                textBoxResult.AppendText(result.Substring(index + 1));
            }
        }

        private void openFile_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;

            labelKey.Text = "";
            textBoxResult.Text = "";
            textBoxBytes.Text = "";
            string filename = openFileDialog1.FileName;
            bytes = "";
            byte[] a = File.ReadAllBytes(filename);
            foreach (var elem in a)
            {
                string str = Convert.ToString(elem, 2).PadLeft(8, '0');
                bytes += str;
                Application.DoEvents();
                textBoxBytes.AppendText(str + Environment.NewLine);
            }
            fileName = Path.GetFileName(filename);
        }



        private void Form1_Load(object sender, EventArgs e)
        {
            initState.Text = "111111111111111111111111";
        }
    }
}
