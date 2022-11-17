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
using System.Numerics;
using System.Security.Cryptography;

namespace ti
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        BigInteger fast_multiplying(BigInteger a, BigInteger digree, BigInteger number)
        {
            BigInteger x = 1;
            while (digree != 0)
            {
                while (digree % 2 == 0)
                {
                    digree /= 2;
                    a = a * a % number;
                }
                digree = digree - 1;
                x = (x * a) % number;
            }
            return x;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBoxP.Text != "" && textBoxQ.Text != "" && textBoxH.Text != "" && textBoxK.Text != "" && textBoxX.Text != "" && textBoxHash.Text != "")
            {
                string str = new string(textBoxP.Text.Where(t => char.IsDigit(t)).ToArray());
                if(str == "")
                {
                    MessageBox.Show("P field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger p = BigInteger.Parse(str);
                str = new string(textBoxQ.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("Q field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger q = BigInteger.Parse(str);
                str = new string(textBoxH.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("H field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger h = BigInteger.Parse(str);
                str = new string(textBoxX.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("X field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger x = BigInteger.Parse(str);
                str = new string(textBoxK.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("K field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger k = BigInteger.Parse(str);
                BigInteger HASH = BigInteger.Parse(new string(textBoxHash.Text.Where(t => char.IsDigit(t)).ToArray()));
                if (MillerRabinTest(q, 10))
                {
                    if (!MillerRabinTest(p, 10))
                    {
                        MessageBox.Show("P must be simple!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }
                    //BigInteger t = (p - 1) % q;
                    if ((p - 1) % q == 0)
                    {
                        if(h <= 1 || h >= (p-1))
                        {
                            MessageBox.Show("h must be in the interval (1; p-1)!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                            return;
                        }
                        BigInteger g = fast_multiplying(h, (p-1)/q, p);
                        if (g > 1)
                        {
                            if (x > 0 && x < q)
                            {
                                if (k > 0 && k < q)
                                {
                                    BigInteger y = fast_multiplying(g, x, p);

                                    BigInteger r = (fast_multiplying(g, k, p)) % q;
                                    BigInteger s = (fast_multiplying(k, q - 2, q) * ((HASH + x * r)) % q);
                                    if (r != 0 && s != 0)
                                    {
                                        textBoxSign.Text = r.ToString() + ',' + s.ToString();
                                        Text = Text + '\n' + r + ' ' + s;
                                        File.WriteAllText(fileNameC,Text);
                                        textBoxHash.Text = "";
                                    }
                                    else
                                        MessageBox.Show("S or R is valu 0.Try to input K again!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                                }
                                else
                                    MessageBox.Show("K should be less than Q", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                            }
                            else
                                MessageBox.Show("X should be less than Q", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        }
                        else
                            MessageBox.Show("G should be more than 1", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    }
                    else
                        MessageBox.Show("Q Is not a divisor of P-1", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                else
                MessageBox.Show("Q must be simple!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);

            }
            else
                MessageBox.Show("Not all values ​​entered!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }

        public bool MillerRabinTest(BigInteger n, int k)
        {

            if (n == 2 || n == 3)
                return true;
            if (n < 2 || n % 2 == 0)
                return false;
           
            BigInteger t = n - 1;

            int s = 0;

            while (t % 2 == 0)
            {
                t /= 2;
                s += 1;
            }

            for (int i = 0; i < k; i++)
            {
                RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();

                byte[] _a = new byte[n.ToByteArray().LongLength];

                BigInteger a;

                do
                {
                    rng.GetBytes(_a);
                    a = new BigInteger(_a);
                }
                while (a < 2 || a >= n - 2);
                BigInteger x = BigInteger.ModPow(a, t, n);
                if (x == 1 || x == n - 1)
                    continue;

                for (int r = 1; r < s; r++)
                {
                    x = BigInteger.ModPow(x, 2, n);
                    if (x == 1)
                        return false;
                    if (x == n - 1)
                        break;
                }

                if (x != n - 1)
                    return false;
            }

            return true;
        }

        public void hesh(byte[] encodedBytes, BigInteger q)
        {
            BigInteger Hesh = 100;

                for (int i = 0; i < encodedBytes.Length; i++)
                {
                    Hesh = fast_multiplying(Hesh + encodedBytes[i], 2, q);
                }
                textBoxHash.Text = Hesh.ToString();
        }
       
        string fileNameC = @"E:\TI\TI_lab2\WindowsFormsApp3\WindowsFormsApp3\шифруем\encrypted.txt";
      
        private void button1_Click_1(object sender, EventArgs e)
        {
            string str = new string(textBoxQ.Text.Where(t => char.IsDigit(t)).ToArray());
            if (str == "")
            {
                MessageBox.Show("First fill all fields!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            BigInteger q = BigInteger.Parse(str);
            if (radioButton1.Checked)
            { 
                if (textBoxQ.Text != "")
                {
                
                    if (MillerRabinTest(q, 10))
                    {
                        
                        if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                        return;
                    string filename = openFileDialog1.FileName;
                    textBoxInput.Text = "";
                    fileNameC = @"E:\TI\TI_lab2\WindowsFormsApp3\WindowsFormsApp3\шифруем\encrypted";
                 
                    Text = File.ReadAllText(filename);
                    byte[] a = File.ReadAllBytes(filename);
                    fileNameC += Path.GetExtension(filename);
                    textBoxInput.Text = String.Join(" ", a);
                        if (Text != "")
                            hesh(textBoxInput.Text.Split(' ').Select(byte.Parse).ToArray(), q);
                        else
                        {
                            BigInteger Hesh = 100;
                            textBoxHash.Text = Hesh.ToString();
                        }
                    }
                    else
                        MessageBox.Show("Q must be simple!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                else
                    MessageBox.Show("Q is not ​​entered!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else{
                if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                    return;
                Text = File.ReadAllText(openFileDialog1.FileName);
                string[] data = Text.Split('\n');
                string numbers = data[data.Length - 1];
                string[] destinationArray = new string[data.Length - 1];
                Array.Copy(data, destinationArray, data.Length - 1);
                hesh(Encoding.Default.GetBytes(String.Join("\n", destinationArray)), q);
                BigInteger s;
                BigInteger r;
                try
                {
                    s = data[data.Length - 1].Split(' ').Select(xy => BigInteger.Parse(xy)).ToArray()[1];
                    r = data[data.Length - 1].Split(' ').Select(xy => BigInteger.Parse(xy)).ToArray()[0];
                } catch
                {
                    MessageBox.Show("File isn't signed!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                str = new string(textBoxX.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("X field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger x = BigInteger.Parse(str);
                str = new string(textBoxP.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("P field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger p = BigInteger.Parse(str);
                if (!MillerRabinTest(p, 10))
                {
                    MessageBox.Show("P must be simple!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                str = new string(textBoxH.Text.Where(t => char.IsDigit(t)).ToArray());
                if (str == "")
                {
                    MessageBox.Show("H field must contain digits!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                BigInteger h = BigInteger.Parse(str);
                BigInteger g = fast_multiplying(h, (p - 1) / q, p);
                BigInteger y = fast_multiplying(g, x, p);
                BigInteger w = fast_multiplying(s, q - 2, q);
                BigInteger u1 = (BigInteger.Parse(textBoxHash.Text) * w) % q;
                BigInteger u2 = (r * w) % q;
                BigInteger v = (fast_multiplying(g, u1, p) * fast_multiplying(y, u2, p) % p) % q;
                if(r == v)
                    MessageBox.Show("The sign is correct!\nr = v = " + r, "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    MessageBox.Show("The sign is not correct!\n r = "+ r +" != v = " + v, "Error", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            textBoxHash.Text = "";
            textBoxSign.Text = "";
            textBoxInput.Text = "";
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            textBoxHash.Text = "";
            textBoxSign.Text = "";
            textBoxInput.Text = "";
        }
    }
}
