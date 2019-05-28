using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Labirint_1
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

        List<MyDataType> spisok = new List<MyDataType>();

        public class MyDataType
        {
            public int a1;
            public int a2;
        }

        static int height = 100, width = 100;
        string[,] frame = new string[height, width];
        string[,] copyframe = new string[height, width];
        void CreateFrame()//создать каркас
        {

         
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if ((i % 2 != 0 && j % 2 != 0) && (i < height - 1 && j < width - 1)) //если ячейка нечетная по x и y, и при этом находится в пределах стен лабиринта
                    {
                        frame[i, j] = "CELL";//то это КЛЕТКА
                        
                    }
                    else frame[i, j] = "WALL"; //Иначе- стена
                }
            }

        }
        int h = 1, w = 1;
        void Algorithm()
        {
            frame[h, w] = "way"+"0";//клетка посещена
            spisok.Add(new MyDataType() { a1 = h, a2 = w });
            while(Ex_UNVISITED()) // сущесвуют ли не посещённые 
            {

                Unvisited_Neighbours(h, w, "CELL");//какие соседи
                if(beside_NB())
                {
                    Choose("way");//рандомный переход куда-то
                }
                else if (spisok.Count!=0)
                {
                    change();
                }
                else
                {
                    MessageBox.Show("Ops:(");
                }

            }
            frame[height-2, width-2] = "Exit";

        }
        void FindExit()
        {
            h = 1;
            w = 1;
            //int findH=1, findW = 1;
            frame[h, w] = "visited";//клетка посещена
            while(frame[h,w]!="visited")
            {
                Unvisited_Neighbours(h, w,"way");//какие соседи
                if (beside_NB())
                {
                    Choose("visited");//рандомный переход куда-то
                }
                else if (spisok.Count != 0)
                {
                    change();
                }
                
            }


        }
        string[] choice = new string[4];

        List<int> generate = new List<int>();

        Random rnd = new Random();
        void Choose(string f)//0-right,1-left,2-down,3-up
        {
            int res = rnd.Next(0, generate.Count);
            int result = generate[res];
            if (result==0)
            {
                frame[h, w + 1] = f;  // разрушили стену
                frame[h, w + 2] = f; ////клетка посещена
                w = w + 2;
            }
            else if (result==1)
            {
                frame[h, w - 1] = f;
                frame[h, w - 2] = f;
                w = w - 2;
            }
            
            else if (result==2)
            {
                frame[h +1, w] = f; 
                frame[h + 2, w] = f;
                h = h + 2;
            }
            else if (result == 3)
            {
                frame[h - 1, w] = f; // разрушили верх
                frame[h - 2, w] = f;
                h = h - 2;
            }
            spisok.Add(new MyDataType() { a1 = h, a2 = w });


            generate.Clear();
        }
        void Transformer() //0-right,1-left,2-down,3-up
        {
            for (int i=0;i<4; i++)
            {
                if (choice[i][0] != 'a')
                {
                    if(choice[i][0]=='r') generate.Add(0);
                    if (choice[i][0] == 'l') generate.Add(1);
                    if (choice[i][0] == 'd') generate.Add(2);
                    if (choice[i][0] == 'u') generate.Add(3);
                }
            }
        }
        
        void change () //выбрать точку, для заполнения 
        {
            
            int i = spisok.Count - 1;
            h = spisok[i].a1;
            w = spisok[i].a2;
            
            spisok.RemoveAt(spisok.Count - 1);
        }
        
        void Unvisited_Neighbours(int h, int w,string f) //есть ли непосещённые соседи
        {
            if (w + 2 < width - 1 )
            {
                if (frame[h, w + 2] == f) choice[0] = "right";    //Есть ли справа непосещённый
                else choice[0] = "a_right";//absence of right
            }
            else choice[0] = "a_right";

            if  (w-2 >0)
            {
                if (frame[h, w - 2] == f) choice[1] = "left";
                else choice[1] = "a_left";
            }
            else choice[1] = "a_left";

            if (h + 2 < height - 1)
            {
                if (frame[h + 2, w] == f) choice[2] = "down";
                else choice[2] = "a_down";
            }
            else choice[2] = "a_down";

            if (h-2 >0)
            {
                if (frame[h - 2, w] == f) choice[3] = "up";
                else choice[3] = "a_up";
            }
            else choice[3] = "a_up";

            Transformer();
        }
        bool beside_NB()
        {
            if (generate.Count > 0) return true;
            else return false;
        }

        int CurrentX = 16, CurrentY = 16;
        int TempI = 1, TempJ = 1;

        private void button3_Click_1(object sender, EventArgs e)
        {
            Player_U.Visible = true;
            Graphics picture = this.CreateGraphics();
            if (WWW.Text == "Clear") picture.Clear(Color.White);
            else
            {
                width = Convert.ToInt32(WWW.Text);
                height = Convert.ToInt32(WWW.Text);

                CreateFrame();
                Algorithm();

                CurrentX = 16;
                CurrentY = 16;
                TempI = 1;
                TempJ = 1;
                Player_U.Location = new Point(CurrentX, CurrentY);
                Point point = new Point();
                point.X = 0;
                point.Y = 0;


                picture.DrawImage(Properties.Resources.White, point);

                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                    {
                        if (frame[i, j] == "WALL")
                        {
                            picture.DrawImage(Properties.Resources.Black, point);
                        }
                        else if (frame[i, j] == "Exit") picture.DrawImage(Properties.Resources.Exit, point);
                        else picture.DrawImage(Properties.Resources.White, point);
                        point.X = point.X + 14;
                    }
                    point.X = 0;
                    point.Y = point.Y + 14;
                }
                spisok.Clear();
                generate.Clear();
                h = 1;
                w = 1;
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
             switch (e.KeyCode)      
             {
                
                case Keys.Down:
                     if(frame[TempI+1,TempJ]!="WALL")
                     {
                         CurrentY = CurrentY + 14;
                         Player_U.Location = new Point(CurrentX, CurrentY);
                        TempI++;
                     }
                     
                     break;
                case Keys.Up:
                    if(frame[TempI-1, TempJ] != "WALL")
                    {
                        CurrentY = CurrentY - 14;
                        Player_U.Location = new Point(CurrentX, CurrentY);
                        TempI--;
                    }
                    break;
                case Keys.Right:
                    if(frame[TempI,TempJ+1]!= "WALL")
                    {
                        CurrentX = CurrentX + 14;
                        Player_U.Location = new Point(CurrentX, CurrentY);
                        TempJ++;
                    }
                    break;
                case Keys.Left:
                    if (frame[TempI, TempJ -1 ] != "WALL")
                    {
                        CurrentX = CurrentX - 14;
                        Player_U.Location = new Point(CurrentX, CurrentY);
                        TempJ--;
                    }
                    break;
            }
            if (frame[TempI, TempJ] == "Exit") MessageBox.Show($"Поздравляю, ты прошёл лабиринт с длинной в {Convert.ToString(width)} !");
        }

        bool Ex_UNVISITED() //сущесвуют ли непоскщённые клетки
        {
            for(int i=0;i<height;i++)
            {
                for(int j=0;j<width;j++)
                {
                    if (frame[i, j] == "CELL") return true;
                }
            }
            return false;
        }
    }
}
