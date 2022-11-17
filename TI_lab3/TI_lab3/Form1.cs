using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TI_lab3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        bool IsTheNumberSimple(long n)
        {
            if (n < 2)
                return false;

            if (n == 2)
                return true;

            for (int i = 2; i < n / 2 + 1; i++)
                if (n % i == 0)
                    return false;

            return true;
        }

        int pow_mod(int a, int digree, int number)
        {
            int x = 1;
            while (digree != 0)
            {
                while (digree % 2 == 0)
                {
                    digree /= 2;
                    a = a*a % number;
                }
                digree = digree - 1;
                x = (x * a) % number;
            }
            return x;
        }


        public static long getExtendGcd(long a, long b, ref long gcd)
        {
            long x0 = 1;
            long x1 = 0;
            long d0 = a;
            gcd = b;
            long y0 = 0;
            long y1 = 1;
            long q, d2, x2, y2;

            while (gcd > 1)
            {
                q = d0 / gcd;
                d2 = d0 % gcd;
                x2 = x0 - q * x1;
                y2 = y0 - q * y1;
                d0 = gcd;
                gcd = d2;
                x0 = x1;
                x1 = x2;
                y0 = y1;
                y1 = y2;
            }

            while (y1 < 0)
                y1 += a;

            return y1;
        }

        void Calculate_e(long d, long EulerFunc)
        {
            long gcd = 1;
            long y = getExtendGcd(EulerFunc, d, ref gcd);
            textBoxE.Text = y.ToString();
        }

        private void radioButtonEncrypt_CheckedChanged(object sender, EventArgs e)
        {
            if(radioButtonEncrypt.Checked)
            {
                groupBox2.Text = "Decryption";
                groupBox3.Text = "Ciphertext";
                button1.Text = "Encrypt";
            }
            else
            {
                groupBox2.Text = "Ciphertext";
                groupBox3.Text = "Decryption";
                button1.Text = "Decrypt";
            }
        }

        bool isOneByte = false;
        private void buttonGenerate_Click(object sender, EventArgs e)
        {
            if (textBoxP.Text != "" && textBoxQ.Text != "")
            {
                string pStr = new string(textBoxP.Text.Where(t => char.IsDigit(t)).ToArray());
                string qStr = new string(textBoxQ.Text.Where(t => char.IsDigit(t)).ToArray());
                if(pStr == "")
                {
                    MessageBox.Show("Only letters ​​entered in the p field!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                if (qStr == "")
                {
                    MessageBox.Show("Only letters ​​entered in the q field!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                int p = int.Parse(pStr);
                int q = int.Parse(qStr);
                if (IsTheNumberSimple(p) && IsTheNumberSimple(q))
                {
                    if (p == q)
                    {
                        MessageBox.Show("Values must be different!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }
                    int n;
                    try
                    {
                        n = p * q;
                        ushort.Parse(n.ToString());
                    }
                    catch {
                        MessageBox.Show("Value is more than 2 bytes!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }
                    textBoxN.Text = n.ToString();
                    try
                    {
                        byte.Parse(n.ToString());
                        isOneByte = true;
                    }
                    catch { isOneByte = false; }
                    int EulerFunc = (p - 1) * (q - 1);
                    textBoxEuler.Text = EulerFunc.ToString();
                    button2.Enabled = true;
                }

                else
                    MessageBox.Show("Entered values must be simple!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
                MessageBox.Show("Not all values ​​entered!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "") return;
            bool yes = false;
            string dStr = new string(textBox1.Text.Where(t => char.IsDigit(t)).ToArray());
            if (dStr == "")
            {
                MessageBox.Show("Only letters ​​entered in the q field!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            long num = long.Parse(dStr);
            if (num <= 1)
            {
                MessageBox.Show("d must be bigger than 1!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (num >= long.Parse(textBoxEuler.Text))
            {
                MessageBox.Show("d must be less than Euler function!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            long gcd = 0;
            getExtendGcd(long.Parse(textBoxEuler.Text), num, ref gcd);
            yes = gcd == 1;
            if (!yes)
            {
                MessageBox.Show("Value must be coprime with the Euler function!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            button1.Enabled = true;
            Calculate_e(num, long.Parse(textBoxEuler.Text));
        }

        delegate int[] ReadDeciphered(string path, long size);
        private void buttonImport_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            string filename = openFileDialog1.FileName;
            textBoxResult.Text = "";
            textBoxInput.Text = "";
            fileNameC = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\шифруем\\encrypted";
            fileNameD = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\шифруем\\decrypted";
            if (radioButtonEncrypt.Checked)
            {
                byte[] a = File.ReadAllBytes(filename);
                fileNameC += Path.GetExtension(filename);
                textBoxInput.Text = String.Join(" ", a);
            }
            else
            {
                ReadDeciphered read;
                if (isOneByte)
                    read = new ReadDeciphered(readPlaintextByte);
                else
                    read = new ReadDeciphered(readCipheredWord);
                fileNameD += Path.GetExtension(filename);
                long size = new FileInfo(filename).Length;
                if (!isOneByte) size /= 2;
                int[] num = read(filename, size);
                textBoxInput.Text = string.Join(" ", num);
            }
        }

        void writeDecipheredByte(string path, int[] Cipher)
        {
            byte[] result = new byte[Cipher.Length];
            result = Cipher.Select(x => (byte)x).ToArray();
            File.WriteAllBytes(path, result);
        }

        void writeCipheredWord(string path, int[] Cipher)
        {
            byte[] arr = new byte[Cipher.Length*2];
            int j = -1;
            for (int i = 0; i < Cipher.Length; i++)
            {
                arr[++j] = (byte)(Cipher[i] >> 8);
                arr[++j] = (byte)(Cipher[i] & 255);
            }
            File.WriteAllBytes(path, arr);
        }

        int[] readCipheredWord(string path, long size)
        {
            byte[] arr = File.ReadAllBytes(path);
            int[] result = new int[size];
            int j = -1;
            for (int i = 0; i < size; i++)
                result[i] = (arr[++j] << 8) + arr[++j];
            return result;
        }

        int[] readPlaintextByte(string path, long size)
        {
            byte[] arr = File.ReadAllBytes(path);
            return arr.Select(x => (int)x).ToArray(); ;
        }

        string fileNameC = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\шифруем\\encrypted";
        string fileNameD = "E:\\TI\\TI_lab2\\WindowsFormsApp3\\WindowsFormsApp3\\шифруем\\decrypted";

        delegate void WriteDeciphered(string path, int[] Cipher);

        private void button1_Click(object sender, EventArgs e)
        {
            textBoxResult.Text = "";
            if (radioButtonEncrypt.Checked)
            {
                WriteDeciphered write;
                if (isOneByte)
                    write = new WriteDeciphered(writeDecipheredByte);
                else
                    write = new WriteDeciphered(writeCipheredWord);
                byte[] encodedBytes = textBoxInput.Text.Split(' ').Select(byte.Parse).ToArray();
                int ek = int.Parse(new string(textBoxE.Text.Where(t => char.IsDigit(t)).ToArray()));
                string str = new string(textBoxN.Text.Where(t => char.IsDigit(t)).ToArray());
                if(str == "")
                {
                    MessageBox.Show("Incorrect n!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                int n = int.Parse(str);
                int[] Cipher = new int[encodedBytes.Length];
               
                for (int i = 0; i < encodedBytes.Length; i++)
                {
                    if (encodedBytes[i] >= n)
                    {
                        MessageBox.Show("Bytes must be less than n!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                    Cipher[i] = pow_mod(encodedBytes[i], ek, n);
                }
                textBoxResult.Text = String.Join(" ", Cipher);
                write(fileNameC, Cipher);

            }
            else
            {
                string str = new string(textBox1.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("Incorrect d!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                int dk = int.Parse(str);
                str = new string(textBoxN.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("Incorrect n!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                int n = int.Parse(str);
                int[] ints = textBoxInput.Text.Split(' ').Select(int.Parse).ToArray();
                byte[] Cipher = new byte[ints.Length];
                for (int i = 0; i < ints.Length; i++)
                {
                    Cipher[i] = (byte)pow_mod(ints[i], dk, n);
                }
                textBoxResult.Text = String.Join(" ", Cipher);
                File.WriteAllBytes(fileNameD, Cipher);

            }

        }

        private void textBoxP_TextChanged(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBoxN.Text = "";
            textBoxEuler.Text = "";
            textBoxE.Text = "";
            button1.Enabled = false;
            button2.Enabled = false;
        }

        private void textBoxQ_TextChanged(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBoxN.Text = "";
            textBoxEuler.Text = "";
            textBoxE.Text = "";
            button1.Enabled = false;
            button2.Enabled = false;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBoxE.Text = "";
        }

        private void textBoxN_TextChanged(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBoxE.Text = "";
            button2.Enabled = false;
        }
    }
}
