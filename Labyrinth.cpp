#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<bits/stdc++.h>



int f=0,f1=0,f2=0,f3=0,point,index=5;
char pic[][10000000]= {"background1.jpg","background2.jpg"};
struct hsc
{
    int point;
    char name[1000];
};
struct hsc score[10000];



void menu();
void menu_click(int x,int y);
int level_1();
void fail();
int level_2();
void sortt();
void high_score();
void help();
void credit();
void ball(int j,int k,int l);
void new_game();
void new_game_2();
int pointco(int *j,int p);
int pointco1(int *j,int p);
void countm(int *co_mo);
int timer(int a,int *b,int s,int time1,int time);
int time_condition(int *sec,int *j,int *k);
void high_score_update();
void object();
void congratulations();
void condition(int *j,int *k);
void condition_2(int *j,int *k);
int level_3();

bool click = false;
void menu_click(int x,int y)
{
    if(x>=350 && x<=600 && y>=150 && y<=200)
    {
        int flag;
        click=true;
        cleardevice();
        flag=level_1();

        f=0;
        f1=0;
        f2=0;
        f3=0;

        if(flag==0)
        {
            high_score_update();
            menu();
        }
        if(flag==1)
        {
            congratulations();
        }

        if(flag==2)
        {
            fail();
            high_score_update();
        }


    }

    ///highscore condition
    else if(x>=350 && x<=600 && y>=230 && y<=280 )
    {
        click=true;
        cleardevice();
        high_score();

    }

    ///help
    else if(x>=400 && x<=550 && y>=310 && y<=360 )
    {
        click=true;
        cleardevice();
        help();

    }

    ///credit
    else if(x>=400 && x<=550 && y>=390 && y<=440 )
    {
        click=true;
        cleardevice();
        credit();
    }


    else if(x>=400 && x<=550 && y>=470 && y<=520 )
    {
        click=true;
        cleardevice();
        exit(0);

    }


}



void menu()
{
    initwindow(1000,700);
    readimagefile("maze.jpg",0,0,1000,700); ///background
    ///new game
    readimagefile("p0.jpg",350,150,600,200);
///highscore
    readimagefile("HS.jpg",350,230,600,280);

///help
    readimagefile("help.jpg",400,310,550,360);

///credit
    readimagefile("credit.jpg",400,390,550,440);
///exit
    readimagefile("exit.jpg",400,470,550,520);


    registermousehandler(WM_LBUTTONDOWN,menu_click);
    click = false;
    int menu_click(int x,int y);


}






int level_1()
{
    cleardevice();
    initwindow(1000,700);
    // settextstyle(8,0,10);
    int time1,time2,time;
    time1 = clock();
    time = 0;
    point=0;
    outtextxy(820,530,"TIMER");
    int mint=0,sec=40;
    int a=100,b=170;
    int temp;
    int co_mo=0;
    int x=0,y=0;
    setcolor(4);
    countm(&co_mo);
    while(1)

    {
        object();
        time_condition(&sec,&a,&b);
        if (timer(mint,&sec,sec,time1,time)==1)
            return 2;


        readimagefile(pic[0],0,0,800,700);
        new_game();
        condition(&a,&b);
        ball(a,b,10);
//        tres(&a,&b);
        temp= pointco(&a,point);
        //point to file

        //Move

        if(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W'))
        {
            countm(&co_mo);
            x=0;
            y=-5;
        }
        if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A'))
        {
            countm(&co_mo);
            x=-5;
            y=0;


        }
        if(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D'))
        {
            countm(&co_mo);
            x=5;
            y=0;


        }
        if(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S'))
        {
            countm(&co_mo);
            x=0;
            y=5;
        }

        a=a+x;
        b=b+y;
        if(GetAsyncKeyState(' '))
            return 0;

        //readimagefile("b.jpg",0,0,1000,700);
        if(a>=775)
        {
            point=1000;
            return 1;
        }

    }
    cleardevice();
}

int level_2()
{
    cleardevice();
    initwindow(1000,700);
    // settextstyle(8,0,10);
    int time1,time2,time;
    time1 = clock();
    time = 0;
    point=1000;
    outtextxy(820,530,"TIMER");
    int mint=1,sec=40;
    int a=130,b=165;
    int temp;
    int co_mo=0;
    int x=0,y=0;
    countm(&co_mo);
    while(1)

    {
        time_condition(&sec,&a,&b);
        if (timer(mint,&sec,sec,time1,time)==1)
            return 2;


        readimagefile(pic[1],0,0,800,700);
        new_game_2();
        condition_2(&a,&b);
        ball(a,b,10);
//        tres(&a,&b);
        temp= pointco1(&a,point);



        //Move

        if(GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W'))
        {
            countm(&co_mo);
            x=0;
            y=-5;
        }
        if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A'))
        {
            countm(&co_mo);
            x=-5;
            y=0;


        }
        if(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D'))
        {
            countm(&co_mo);
            x=5;
            y=0;


        }
        if(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S'))
        {
            countm(&co_mo);
            x=0;
            y=5;
        }

        a=a+x;
        b=b+y;
        if(GetAsyncKeyState('E'))
            return 0;

        //readimagefile("b.jpg",0,0,1000,700);
        if(a>775)
            return 1;

    }
    cleardevice();
}


void credit()
{
    initwindow(1000,1000);
    int flag=1;
    cleardevice();
    readimagefile("crdt.jpg",0,0,1000,700);
    settextstyle(8,HORIZ_DIR,0);

    outtextxy(100,650,"Press any key to go back");

    if (flag==1)
    {

        getch();
        menu();
    }
}
void help()
{
    initwindow(1000,1000);
    int flag=1;
    cleardevice();
    readimagefile("hlp.jpg",0,0,1000,700);
    settextstyle(8,HORIZ_DIR,0);

    outtextxy(100,650,"Press any key to go back");

    if (flag==1)
    {

        getch();
        menu();
    }

}
void congratulations()
{
    cleardevice();
    // initwindow(1000,700);
    readimagefile("congo.jpg",0,0,1000,700);
    bar(220,430,320,480);
    settextstyle(10,HORIZ_DIR,0);

    //outtextxy(875,198,"HIGH SCORE");
    char arr[50];
    sprintf(arr,"%d",point);
    setcolor(3);
    outtextxy(230,440,arr);

    while(1)
    {
        char c=getch();
        if(c==' ')
        {
            break;
        }
    }
    int  flag1=level_2();
    f=0;
    f1=0;
    f2=0;
    f3=0;

    if(flag1==0)
    {
        high_score_update();
        menu();
    }
    if(flag1==1){
        readimagefile("congo.jpg",0,0,1000,700);
    getch();
    menu();
    }
    if(flag1==2)
    {
        fail();
        high_score_update();

    }

}


void high_score()
{
    initwindow(1000,1000);

    int i;
    FILE *input=fopen("hhh.txt","r");
    for(i=0; i<5; i++)
    {
        fscanf(input,"%d",&score[i].point);
        fscanf(input,"%s",score[i].name);
    }
    fclose(input);

    int flag=1;
    cleardevice();
    readimagefile("hsc.jpg",0,0,1000,700);
    settextstyle(8,HORIZ_DIR,0);
    outtextxy(100,500,"Press any key to go back");
    for(int i=0; i<5; i++)
    {
        char arr[50],arr2[50],arrn[500];
        sprintf(arr2,"%d:",i+1);
        sprintf(arr,"%d",score[i].point);
        sprintf(arrn,"%s",score[i].name);
        setcolor(3);
        outtextxy(180,305+i*40,arr2);
        setcolor(14);
        outtextxy(440,305+i*40,arr);
        outtextxy(240,305+i*40,arrn);

    }
    if (flag==1)
    {

        getch();
        menu();

    }
}


void high_score_update()
{
    score[index].point=point;
    initwindow(1000,1000);
    readimagefile("b.jpg",0,0,1000,1000);
    for(int i=0; i<=10; i++)
    {
        settextstyle(10,HORIZ_DIR,0);

    outtextxy(100,198,"ENTER YOUR NAME");
      outtextxy(100,498,"Press space");
      bar(100,250,300,250);
        char c=getch();
        char arr[50];
        sprintf(arr,"%c",c);
        setcolor(3);

        outtextxy(200+i*30,250,arr);
        score[index].name[i]=c;

        if(c==' ')
            break;
    }
    index++;
    sortt();
}

void sortt()
{
    for(int i=0; i<=index; i++)
    {
        for(int j=0; j<=index; j++)
        {
            if(score[i].point>score[j].point)
            {
                struct hsc temp=score[i];
                score[i]=score[j];
                score[j]=temp;
            }
        }
    }
    FILE *output=fopen("hhh.txt","w");
    for(int i=0; i<5; i++)
        fprintf(output,"%d %s\n",score[i].point,score[i].name);
        fclose(output);
}

void ball(int j,int k,int l)   //ball
{
    setcolor(8);
    circle(j,k,l);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(j,k,8);


    circle(j-4,k-5,l-7);

    setfillstyle(SOLID_FILL,BLACK);
    floodfill(j-4,k-5,8);
    circle(j+4,k-5,l-7);

    setfillstyle(SOLID_FILL,BLACK);
    floodfill(j+4,k-5,8);
    circle(j,k+3,l-6);
    setfillstyle(SOLID_FILL,RED);
    floodfill(j,k+4,8);

}

int pointco1(int *j,int p)
{

    if(*j>100&&*j<=150) point=1200;
    if(*j>150&&*j<=200) point=1500;
    if(*j>200&&*j<=250) point=2000;
    if(*j>250&&*j<=300) point=2500;
    if(*j>300&&*j<=350) point=3000;
    if(*j>350&&*j<=200) point=3500;
    if(*j>400&&*j<=450) point=4000;
    if(*j>450&&*j<=500) point=4500;
    if(*j>500&&*j<=550) point=5000;
    if(*j>550&&*j<=600) point=5500;
    if(*j>600&&*j<=650) point=6000;
    if(*j>650&&*j<=700) point=6500;
    if(*j>700&&*j<=750) point=7000;
    if(*j>750&&*j<=770) point=7500;
    if(*j>775) point=10000;
    setcolor(9);
    outtextxy(835,50,"SCORE");
    char arr[50];
    sprintf(arr,"%d",point);
    setcolor(3);
    outtextxy(840,70,arr);
    return point;
}

void fail()
{
    cleardevice();
    // initwindow(1000,700);
    readimagefile("fail.jpg",0,0,1000,700);
    bar(220,530,320,580);
    settextstyle(10,HORIZ_DIR,0);

    //outtextxy(875,198,"HIGH SCORE");
    char arr[50];
    sprintf(arr,"%d",point);
    setcolor(3);
    outtextxy(230,540,arr);

    while(1)
    {
        char c=getch();
        if(c==' ')
        {
            menu();
            break;
        }
    }
}
void countm(int *co_mo)
{

    settextstyle(0,HORIZ_DIR,0);
    setcolor(*co_mo%14);
    bar(820,170,970,270);
    setcolor(8);
    outtextxy(875,198,"MOVE");
    char arr[50];
    sprintf(arr,"%d",*co_mo/2);
    setcolor(3);
    outtextxy(890,215,arr);
    *co_mo=*co_mo+1;
    setcolor(12);
    outtextxy(820,280,"w -> Up");
    outtextxy(820,300,"s -> Down");
    outtextxy(820,320,"a -> Left");
    outtextxy(820,340,"d -> Right");
}
int pointco(int *j,int p)
{

    if(*j>100&&*j<=150) point=100;
    if(*j>150&&*j<=200) point=150;
    if(*j>200&&*j<=250) point=200;
    if(*j>250&&*j<=300) point=250;
    if(*j>300&&*j<=350) point=300;
    if(*j>350&&*j<=200) point=350;
    if(*j>400&&*j<=450) point=400;
    if(*j>450&&*j<=500) point=450;
    if(*j>500&&*j<=550) point=500;
    if(*j>550&&*j<=600) point=550;
    if(*j>600&&*j<=650) point=600;
    if(*j>650&&*j<=700) point=650;
    if(*j>700&&*j<=750) point=700;
    if(*j>750&&*j<=770) point=750;
    if(*j>775) point=1000;
    setcolor(9);
    outtextxy(835,50,"SCORE");
    char arr[50];
    sprintf(arr,"%d",point);
    setcolor(3);
    outtextxy(840,70,arr);
    return point;
}
int timer(int a,int *b,int s,int time1,int time)
{

    char TIME[100];
    int time2=clock();
    if(time!=(time2-time1)/CLOCKS_PER_SEC)
    {
        time = (time2-time1)/CLOCKS_PER_SEC;

        if(time%60<10)
        {
            if(time/60<10) sprintf(TIME,"0%d:0%d/%.2d:%.2d", time/60,time%60,a,*b);
            else sprintf(TIME,"%d:0%d/%.2d:%.2d", time/60,time%60,a,*b);
        }
        else if(time/60<10)
        {
            sprintf(TIME,"0%d:%d/%.2d:%.2d", time/60,time%60,a,*b);
        }
        else sprintf(TIME,"%d:%d/%.2d:%.2d", time/60,time%60,a,*b);
        outtextxy(820,550,TIME);
        if(time/60==a&&time%60+(*b-s)==*b) return 1;
    }


}

int time_condition(int *sec,int *j,int *k)
{

    if(f==0&&*j>585&&*j<615 && *k>315&&*k<345)
    {
        *sec=*sec+5;
        f=1;
        readimagefile("b.jpg",585,315,615,345);
    }
    if(*j>205&&*j<235 && *k>235&&*k<265&&f1==0)
    {
        *sec=*sec+5;
        f1=1;
        readimagefile("b.jpg",205,235,235,265);
    }
    if(f2==0&&*j>475&&*j<505 && *k>460&&*k<490)
    {
        *sec=*sec-5;
        f2=1;
        readimagefile("b.jpg",475,460,505,490);
    }
    if(*j>205&&*j<235 && *k>470&&*k<505&&f3==0)
    {
        *sec=*sec-5;
        f3=1;
        readimagefile("b.jpg",205,470,235,505);
    }
}

void new_game()
{
    // readimagefile("b.jpg",0,0,1000,700);

    setcolor(4);
    line(80,600,725,600);//horizontal
    line(80,150,725,150);
    line(725,560,775,560);
    line(725,600,775,600);
    line(120,190,685,190);
    line(120,375,470,375);
    line(240,415,440,415);
    line(180,230,725,230);
    line(180,325,520,325);
    line(220,277,580,277);


    line(676,350,676,600); //vertical
    line(120,560,120,190);
    line(725,150,725,560);
    line(80,600, 80,150);
    line(160,415,160,600);
    line(200,375,200,560);
    line(240,415,240,600);
    line(440,415,440,600);
    line(580,277,580,600);
    line(628,230,628,500);
    line(520,325,520,520);
    line(180,230,180,325);
    setcolor(14);
    circle(770,580,15);

}



void new_game_2()
{
    setcolor(RED);
    object();
    line(80,150,80,600);  //vertical
    line(725,150,725,560);
    line(120,150,120,350);
    line(720,560,775,560);
    line(700,600,775,600);

    line(200,230,200,270);
    line(240,270,240,310);
    line(160,310,160,350);
    line(240,350,240,390);
    line(120,520,120,600);
    line(120,390,120,430);
    line(120,460,120,490);
    line(200,390,200,520);
    line(240,520,240,560);
    line(200,560,200,600);
    line(240,430,240,460);
    line(280,390,280,430);
    line(280,490,280,600);

    line(280,230,280,310);
    line(350,190,350,270);
    line(320,270,320,390);
    line(320,430,320,600);
    line(430,230,430,270);
    line(350,350,350,460);
    line(350,490,350,560);
    line(685,190,685,230);
    line(430,150,430,190);
    line(510,190,510,230);
    line(590,150,590,230);
    line(640,190,640,270);

    line(470,270,470,310);
    line(685,270,685,310);
    line(590,270,590,310);
    line(430,310,430,350);
    line(510,310,510,350);
    line(550,310,550,350);
    line(470,350,470,390);
    line(510,390,510,430);
    line(390,390,390,430);
    line(430,430,430,460);
    line(510,390,510,430);


    ///chnge

    line(640,310,640,320);

    line(640,350,640,430);
    ///ei dui line



    line(685,350,685,430);
    line(590,350,590,390);
    line(550,390,550,460);
    line(430,520,430,600);
    line(470,520,470,600);
    line(550,490,550,560);
    line(510,560,510,600);
    line(510,460,510,490);
    line(640,460,640,490);
    line(685,490,685,520);
    line(590,520,590,560);
    line(640,560,640,600);
    line(685,560,685,600);
    line(470,190,470,230);




    line(80,150,725,150); //horizontal
    line(120,190,160,190);
    line(120,230,160,230);
    line(120,270,200,270);
    line(200,230,240,230);

    line(120,310,240,310);
    line(160,350,280,350);
    line(80,430,160,430);

    line(80,490,120,490);
    line(120,460,160,460);


    line(80,600,725,600);
    line(120,520,160,520);
    line(120,560,160,560);
    line(160,390,200,390);
    line(160,490,200,490);
    line(200,520,240,520);
    line(200,430,280,430);
    line(240,490,280,490);
    line(280,230,320,230);
    line(200,190,350,190);
    line(320,270,390,270);
    line(280,390,320,390);
    line(280,460,320,460);
    line(280,310,390,310);
    line(350,350,390,350);
    line(350,460,390,460);
    line(685,230,725,230);
    line(380,190,430,190);
    line(350,230,510,230);
    line(510,190,550,190);
    line(550,230,590,230);
    line(430,270,685,270);
    line(640,310,685,310);
    line(430,350,550,350);
    line(350,390,510,390);
    line(430,430,590,430);
    line(430,460,470,460);
    line(640,310,685,310);
    line(590,350,640,350);
    line(550,390,590,390);
    line(640,390,685,390);
    line(685,430,725,430);
    line(350,490,550,490);
    line(350,520,390,520);
    line(470,520,510,520);
    line(390,560,430,560);
    line(510,560,590,560);
    line(590,460,685,460);
    line(590,490,685,490);
    line(590,520,685,520);
    setcolor(14);
    circle(770,580,15);
}


void object()
{


    setfillstyle(7,CYAN);
    if(f1==0)
        bar(205,235,235,265);
    setfillstyle(8,WHITE);
    if(f==0)
        bar(585,315,615,345);


    setcolor(8);

    if(f2==0)
    {
        line(490,460,475,490);

        line(475,490,505,490);
        line(490,460,505,490);
        setfillstyle(SOLID_FILL,8);
        floodfill(490,475,8);
    }

///making a triangle
/// minus
    setcolor(BLUE);
    if(f3==0)
    {
        line(220,475,205,505);

        line(220,475,235,505);
        line(205,505,235,505);
        setfillstyle(1,BLUE);
        floodfill(220,490,BLUE);
    }






}


void condition(int *j,int *k)

{

    if(*k>=590 && *k<=610 && *j>=70 &&* j<=725)
    {
        if(*k<=600) *k-=10;
        *k+=5;
    }


    if(*k>=550 && *k<=570 && *j>=715 &&* j<=775)
    {
        if(*k<=560) *k-=10;
        *k+=5;
    }

    if(*k>=590 && *k<=610 && *j>=715 &&* j<=775)
    {
        if(*k<=600) *k-=10;
        *k+=5;
    }
    if(*k>=180 && *k<=200 && *j>=110 &&* j<=685)
    {
        if(*k<=190) *k-=10;
        *k+=5;
    }
    if(*k>=365 && *k<=385 && *j>=110 &&* j<=470)
    {
        if(*k<=375) *k-=10;
        *k+=5;
    }
    if(*k>=405 && *k<=425 && *j>=230 &&* j<=440)
    {
        if(*k<=415) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=170 &&* j<=725)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }

    if(*k>=315 && *k<=335 && *j>=170 &&* j<=520)
    {
        if(*k<=325) *k-=10;
        *k+=5;
    }
    if(*k>=315 && *k<=325 && *j>=510 &&* j<=520)
    {
        if(*k<=520) *k-=10;
        *k+=5;
    }
    if(*k>=267 && *k<=287 && *j>=210 &&* j<=580)
    {
        if(*k<=277) *k-=10;
        *k+=5;
    }
    if(*k>=140 && *k<=160 && *j>=70 &&* j<=725)
    {
        if(*k<=150) *k-=10;
        *k+=5;
    }

//hori
    if(*j>=666 && *j<=686 && *k>=340 &&* k<=600)
    {
        if(*j<=676) *j-=10;
        *j+=5;
    }

    if(*j>=110 && *j<=130 && *k>=180 &&* k<=560)
    {
        if(*j<=120) *j-=10;
        *j+=5;
    }

    if(*j>=715 && *j<=735 && *k>=140 &&* k<=560)
    {
        if(*j<=725) *j-=10;
        *j+=5;
    }
    if(*j>=70 && *j<=90 && *k>=140 &&* k<=600)
    {
        if(*j<=80) *j-=10;
        *j+=5;
    }
    if(*j>=150 && *j<=170 && *k>=405 &&* k<=600)
    {
        if(*j<=160) *j-=10;
        *j+=5;
    }
    if(*j>=190 && *j<=210 && *k>=365 &&* k<=560)
    {
        if(*j<=200) *j-=10;
        *j+=5;
    }

    if(*j>=230 && *j<=250 && *k>=405 &&* k<=600)
    {
        if(*j<=240) *j-=10;
        *j+=5;
    }
    if(*j>=430 && *j<=450 && *k>=405 &&* k<=600)
    {
        if(*j<=440) *j-=10;
        *j+=5;
    }
    if(*j>=570 && *j<=590 && *k>=267 &&* k<=600)
    {
        if(*j<=580) *j-=10;
        *j+=5;
    }
    if(*j>=618 && *j<=638 && *k>=220 &&* k<=500)
    {
        if(*j<=628) *j-=10;
        *j+=5;
    }
    if(*j>=510 && *j<=530 && *k>=315 &&* k<=520)
    {
        if(*j<=520) *j-=10;
        *j+=5;
    }

    if(*j>=170 && *j<=190 && *k>=220 &&* k<=325)
    {
        if(*j<=180) *j-=10;
        *j+=5;
    }
}
void condition_2(int *j,int *k)
{
//hori condition
    if(*k>=590 && *k<=610 && *j>=690 &&* j<=775)
    {
        if(*k<=600) *k-=10;
        *k+=5;
    }
    if(*k>=550 && *k<=570 && *j>=710 &&* j<=775)
    {
        if(*k<=560) *k-=10;
        *k+=5;
    }
    if(*k>=140 && *k<=160 && *j>=70 && *j<=725)
    {
        if(*k<=150) *k-=10;
        *k+=5;
    }


    if(*k>=180 && *k<=200 && *j>=110 && *j<=160)
    {
        if(*k<=190) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=110 && *j<=160)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }


    if(*k>=260 && *k<=280 && *j>=110 && *j<=200)
    {
        if(*k<=270) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=190 && *j<=240)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }

    if(*k>=300 && *k<=320 && *j>=110 && *j<=240)
    {
        if(*k<=310) *k-=10;
        *k+=5;
    }
    if(*k>=340 && *k<=360 && *j>=150 && *j<=280)
    {
        if(*k<=350) *k-=10;
        *k+=5;
    }


    if(*k>=420 && *k<=440 && *j>=70 && *j<=160)
    {
        if(*k<=430) *k-=10;
        *k+=5;
    }
    if(*k>=480 && *k<=500 && *j>=70 && *j<=120)
    {
        if(*k<=490) *k-=10;
        *k+=5;
    }

    if(*k>=450 && *k<=470 && *j>=110 && *j<=160)
    {
        if(*k<=460) *k-=10;
        *k+=5;
    }
    if(*k>=590 && *k<=610 && *j>=70 && *j<=725)
    {

        if(*k<=600) *k-=10;
        *k+=5;
    }


    if(*k>=510 && *k<=530 && *j>=110 && *j<=160)
    {
        if(*k<=520) *k-=10;
        *k+=5;
    }
    if(*k>=550 && *k<=570 && *j>=110 && *j<=160)
    {
        if(*k<=560) *k-=10;
        *k+=5;
    }

    if(*k>=380 && *k<=400 && *j>=150 && *j<=200)
    {
        if(*k<=390) *k-=10;
        *k+=5;
    }
    if(*k>=480 && *k<=500 && *j>=150 && *j<=200)
    {
        if(*k<=490) *k-=10;
        *k+=5;
    }

    if(*k>=510 && *k<=530 && *j>=190 && *j<=240)
    {
        if(*k<=520) *k-=10;
        *k+=5;
    }
    if(*k>=420 && *k<=440 && *j>=190 && *j<=280)
    {
        if(*k<=430) *k-=10;
        *k+=5;
    }

    if(*k>=480 && *k<=500 && *j>=230 && *j<=280)
    {
        if(*k<=490) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=270 && *j<=320)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }

    if(*k>=180 && *k<=200 && *j>=190 && *j<=350)
    {
        if(*k<=190) *k-=10;
        *k+=5;
    }
    if(*k>=260 && *k<=280 && *j>=310 && *j<=390)
    {
        if(*k<=270) *k-=10;
        *k+=5;
    }


    if(*k>=380 && *k<=400 && *j>=270 && *j<=320)
    {
        if(*k<=390) *k-=10;
        *k+=5;
    }
    if(*k>=450 && *k<=470 && *j>=270 && *j<=320)
    {
        if(*k<=460) *k-=10;
        *k+=5;
    }

    if(*k>=300 && *k<=320 && *j>=270 && *j<=390)
    {
        if(*k<=310) *k-=10;
        *k+=5;
    }
    if(*k>=340 && *k<=360 && *j>=350 && *j<=390)
    {
        if(*k<=350) *k-=10;
        *k+=5;
    }

    if(*k>=450 && *k<=470 && *j>=340 && *j<=390)
    {
        if(*k<=460) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=675 && *j<=725)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }


    if(*k>=180 && *k<=200 && *j>=380 && *j<=430)
    {
        if(*k<=190) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=340 && *j<=510)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }

    if(*k>=180 && *k<=200 && *j>=500 && *j<=550)
    {
        if(*k<=190) *k-=10;
        *k+=5;
    }
    if(*k>=220 && *k<=240 && *j>=540 && *j<=590)
    {
        if(*k<=230) *k-=10;
        *k+=5;
    }

    if(*k>=260 && *k<=280 && *j>=420 && *j<=685)
    {
        if(*k<=270) *k-=10;
        *k+=5;
    }
    if(*k>=300 && *k<=320 && *j>=630 && *j<=685)
    {
        if(*k<=310) *k-=10;
        *k+=5;
    }

    if(*k>=340 && *k<=360 && *j>=420 && *j<=550)
    {
        if(*k<=350) *k-=10;
        *k+=5;
    }
    if(*k>=380 && *k<=400 && *j>=340 && *j<=510)
    {
        if(*k<=390) *k-=10;
        *k+=5;
    }


    if(*k>=420 && *k<=440 && *j>=420 && *j<=590)
    {
        if(*k<=430) *k-=10;
        *k+=5;
    }
    if(*k>=450 && *k<=470 && *j>=420 && *j<=470)
    {
        if(*k<=460) *k-=10;
        *k+=5;
    }

    if(*k>=300 && *k<=320 && *j>=630 && *j<=685)
    {
        if(*k<=310) *k-=10;
        *k+=5;
    }
    if(*k>=340 && *k<=360 && *j>=580 && *j<=640)
    {
        if(*k<=350) *k-=10;
        *k+=5;
    }

    if(*k>=380 && *k<=400 && *j>=540 && *j<=590)
    {
        if(*k<=390) *k-=10;
        *k+=5;
    }
    if(*k>=380 && *k<=400 && *j>=630 && *j<=685)
    {
        if(*k<=390) *k-=10;
        *k+=5;
    }

    if(*k>=420 && *k<=440 && *j>=675 && *j<=725)
    {
        if(*k<=430) *k-=10;
        *k+=5;
    }
    if(*k>=480 && *k<=500 && *j>=340 && *j<=550)
    {
        if(*k<=490) *k-=10;
        *k+=5;
    }

    if(*k>=510 && *k<=530 && *j>=340 && *j<=390)
    {
        if(*k<=520) *k-=10;
        *k+=5;
    }
    if(*k>=530 && *k<=540 && *j>=460 && *j<=510)
    {
        if(*k<=520) *k-=10;
        *k+=5;
    }

    if(*k>=550 && *k<=570 && *j>=380 && *j<=430)
    {
        if(*k<=560) *k-=10;
        *k+=5;
    }
    if(*k>=550 && *k<=570 && *j>=500 && *j<=590)
    {
        if(*k<=560) *k-=10;
        *k+=5;
    }
    if(*k>=450 && *k<=470 && *j>=580 && *j<=685)
    {
        if(*k<=460) *k-=10;
        *k+=5;
    }

    if(*k>=480 && *k<=500 && *j>=580 && *j<=685)
    {
        if(*k<=490) *k-=10;
        *k+=5;
    }
    if(*k>=510 && *k<=530 && *j>=580 && *j<=685)
    {
        if(*k<=520) *k-=10;
        *k+=5;
    }


//vertical
    if(*j>=70 && *j<=90 && *k>=140 && *k<=600)
    {
        if(*j<=80) *j-=10;
        *j+=5;
    }
    if(*j>=715 && *j<=735 && *k>=140 && *k<=560)
    {
        if(*j<=725) *j-=10;
        *j+=5;
    }

    if(*j>=130 && *j<=140 && *k>=110 && *k<=350)
    {
        if(*j<=120) *j-=10;
        *j+=5;
    }
    if(*j>=190 && *j<=210 && *k>=220 && *k<=270)
    {
        if(*j<=200) *j-=10;
        *j+=5;
    }

    if(*j>=230 && *j<=250 && *k>=260 && *k<=310)
    {
        if(*j<=240) *j-=10;
        *j+=5;
    }
    if(*j>=150 && *j<=170 && *k>=300 && *k<=350)
    {
        if(*j<=160) *j-=10;
        *j+=5;
    }

    if(*j>=230 && *j<=250 && *k>=340 && *k<=390)
    {
        if(*j<=240) *j-=10;
        *j+=5;
    }
    if(*j>=110 && *j<=130 && *k>=510 && *k<=600)
    {
        if(*j<=120) *j-=10;
        *j+=5;
    }

    if(*j>=110 && *j<=130 && *k>=380 && *k<=430)
    {
        if(*j<=120) *j-=10;
        *j+=5;
    }
    if(*j>=110 && *j<=130 && *k>=450 && *k<=490)
    {
        if(*j<=120) *j-=10;
        *j+=5;
    }

    if(*j>=190 && *j<=210 && *k>=380 && *k<=520)
    {
        if(*j<=200) *j-=10;
        *j+=5;
    }
    if(*j>=230 && *j<=250 && *k>=510 && *k<=560)
    {
        if(*j<=240) *j-=10;
        *j+=5;
    }

    if(*j>=190 && *j<=210 && *k>=550 && *k<=600)
    {
        if(*j<=200) *j-=10;
        *j+=5;
    }
    if(*j>=230 && *j<=250 && *k>=420 && *k<=460)
    {
        if(*j<=240) *j-=10;
        *j+=5;
    }

    if(*j>=270 && *j<=290 && *k>=380 && *k<=430)
    {
        if(*j<=280) *j-=10;
        *j+=5;
    }
    if(*j>=270 && *j<=290 && *k>=480 && *k<=600)
    {
        if(*j<=280) *j-=10;
        *j+=5;
    }
    if(*j>=270 && *j<=290 && *k>=220 && *k<=320)
    {
        if(*j<=280) *j-=10;
        *j+=5;
    }

    if(*j>=340 && *j<=350 && *k>=180 && *k<=270)
    {
        if(*j<=350) *j-=10;
        *j+=5;
    }
    if(*j>=310 && *j<=330 && *k>=260 && *k<=390)
    {
        if(*j<=320) *j-=10;
        *j+=5;
    }
    if(*j>=310 && *j<=330 && *k>=420 && *k<=600)
    {
        if(*j<=320) *j-=10;
        *j+=5;
    }

    if(*j>=420 && *j<=440 && *k>=220 && *k<=270)
    {
        if(*j<=430) *j-=10;
        *j+=5;
    }
    if(*j>=340 && *j<=360 && *k>=340 && *k<=460)
    {
        if(*j<=350) *j-=10;
        *j+=5;
    }

    if(*j>=340 && *j<=360 && *k>=480 && *k<=560)
    {
        if(*j<=350) *j-=10;
        *j+=5;
    }

    if(*j>=675 && *j<=695 && *k>=180 && *k<=230)
    {
        if(*j<=685) *j-=10;
        *j+=5;
    }

    if(*j>=420 && *j<=440 && *k>=140 && *k<=190)
    {
        if(*j<=430) *j-=10;
        *j+=5;
    }


    if(*j>=500 && *j<=520 && *k>=180 && *k<=230)
    {
        if(*j<=510) *j-=10;
        *j+=5;
    }

    if(*j>=580 && *j<=600 && *k>=140 && *k<=230)
    {
        if(*j<=590) *j-=10;
        *j+=5;
    }

    if(*j>=630 && *j<=650 && *k>=180 && *k<=270)
    {
        if(*j<=640) *j-=10;
        *j+=5;
    }

    if(*j>=460 && *j<=480 && *k>=260 && *k<=310)
    {
        if(*j<=470) *j-=10;
        *j+=5;
    }

    if(*j>=675 && *j<=695 && *k>=260 && *k<=310)
    {
        if(*j<=685) *j-=10;
        *j+=5;
    }

    if(*j>=580 && *j<=600 && *k>=260 && *k<=310)
    {
        if(*j<=590) *j-=10;
        *j+=5;
    }


    if(*j>=420 && *j<=440 && *k>=300 && *k<=350)
    {
        if(*j<=430) *j-=10;
        *j+=5;
    }

    if(*j>=500 && *j<=520 && *k>=300 && *k<=350)
    {
        if(*j<=510) *j-=10;
        *j+=5;
    }

    if(*j>=540 && *j<=560 && *k>=300 && *k<=350)
    {
        if(*j<=550) *j-=10;
        *j+=5;
    }

    if(*j>=460 && *j<=480 && *k>=340 && *k<=390)
    {
        if(*j<=470) *j-=10;
        *j+=5;
    }

    if(*j>=500 && *j<=520 && *k>=380 && *k<=430)
    {
        if(*j<=510) *j-=10;
        *j+=5;
    }

    if(*j>=380 && *j<=400 && *k>=380 && *k<=430)
    {
        if(*j<=390) *j-=10;
        *j+=5;
    }

    if(*j>=420 && *j<=440 && *k>=420 && *k<=460)
    {
        if(*j<=430) *j-=10;
        *j+=5;
    }

    if(*j>=500 && *j<=520 && *k>=380 && *k<=430)
    {
        if(*j<=510) *j-=10;
        *j+=5;
    }


    ///sorto

    if(*j>=630 && *j<=650 && *k>=300 && *k<=320)
    {
        if(*j<=640) *j-=10;
        *j+=5;
    }
    if(*j>=630 && *j<=650 && *k>=340 && *k<=430)
    {
        if(*j<=640) *j-=10;
        *j+=5;
    }
    if(*j>=110 && *j<=130 && *k>=140 && *k<=350)
    {
        if(*j<=120) *j-=10;
        *j+=5;
    }





    if(*j>=675 && *j<=695 && *k>=340 && *k<=430)
    {
        if(*j<=685) *j-=10;
        *j+=5;
    }

    if(*j>=580 && *j<=600 && *k>=340 && *k<=390)
    {
        if(*j<=590) *j-=10;
        *j+=5;
    }

    if(*j>=540 && *j<=560 && *k>=380 && *k<=460)
    {
        if(*j<=550) *j-=10;
        *j+=5;
    }

    if(*j>=420 && *j<=440 && *k>=520 && *k<=600)
    {
        if(*j<=430) *j-=10;
        *j+=5;
    }

    if(*j>=460 && *j<=480 && *k>=510 && *k<=600)
    {
        if(*j<=470) *j-=10;
        *j+=5;
    }

    if(*j>=540 && *j<=560 && *k>=480 && *k<=560)
    {
        if(*j<=550) *j-=10;
        *j+=5;
    }

    if(*j>=500 && *j<=520 && *k>=550 && *k<=600)
    {
        if(*j<=510) *j-=10;
        *j+=5;
    }


    if(*j>=500 && *j<=520 && *k>=450 && *k<=490)
    {
        if(*j<=510) *j-=10;
        *j+=5;
    }

    if(*j>=630 && *j<=650 && *k>=450 && *k<=490)
    {
        if(*j<=640) *j-=10;
        *j+=5;
    }


    if(*j>=675 && *j<=695 && *k>=480 && *k<=520)
    {
        if(*j<=685) *j-=10;
        *j+=5;
    }

    if(*j>=580 && *j<=600 && *k>=510 && *k<=560)
    {
        if(*j<=590) *j-=10;
        *j+=5;
    }

    if(*j>=630 && *j<=650 && *k>=550 && *k<=600)
    {
        if(*j<=640) *j-=10;
        *j+=5;
    }

    if(*j>=675 && *j<=690 && *k>=550 && *k<=600)
    {
        if(*j<=685) *j-=10;
        *j+=5;
    }



    if(*j>=460 && *j<=480 && *k>=180 && *k<=230)
    {
        if(*j<=470) *j-=10;
        *j+=5;
    }

}





int main()
{

    menu();
    getch();
}

