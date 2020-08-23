/*#include<bits/stdc++.h>
#include <windows.h>

//作者 cdqz_ssw 
#define l1 262
#define l2 294
#define l3 330
#define l4 349
#define l5 392
#define l6 440
#define l7 493

#define n1 532
#define n2 588
#define n3 660
#define n4 698
#define n5 784
#define n6 880
#define n7 988

#define h1 1046
#define h2 1175
#define h3 1319
#define h4 1397
#define h5 1568
#define h6 1760
#define h7 1976

#define A 1600*1.25 //四拍
#define B 800*1.25  //两拍
#define C 400*1.25  //一拍
#define D 200*1.25  //半拍
#define E 100*1.25  //1/4拍
#define F 50*1.25   //1/8拍

#define S(i) Sleep(i)
#define wq( i , j ) Beep( i , j )

int  main(){
    wq(n3,D);wq(n4,D);wq(n3,D);wq(n4,D);wq(n5,C);wq(n3,D);wq(n4,D);

    wq(n3,D);wq(n4,D);wq(n5,C);wq(n5,D);wq(n4,D);wq(n3,D);wq(n4,D);

    wq(n3,E);wq(n1,D);wq(n1,D);wq(n1,E);wq(l6,D);
    wq(n3,E);wq(n1,D);wq(n1,D);wq(n1,E);wq(l6,D);

    wq(n1,E);wq(n1,D);wq(n1,D);wq(n1,E);wq(l6,D);wq(n3,C);S(C);
    //-----------------------------------------作者 ssw02 -----
    //----------C1----D0.5---------------------------------------2
    wq(n3,D);wq(n4,D);wq(n3,D);wq(n4,D);wq(n5,C);wq(n3,D);wq(n4,D);

    wq(n3,D);wq(n4,D);wq(n5,C);wq(n5,D);wq(n4,D);wq(n3,D);wq(n4,D);

    wq(n3,E);wq(n1,D);wq(n1,D);wq(n1,E);wq(l6,D);
    wq(n3,E);wq(n1,D);wq(n1,D);wq(n1,E);wq(n2,D);

    wq(n1,E);wq(n1,D);wq(n1,D);wq(n1,E);wq(n3,D);wq(n3,C);S(C);
    //-----------------------------------------作者 ssw02 -----
    //----------C1----D0.5---------------------------------------3
    wq(n5,C);wq(n3,C);wq(n2,C);wq(n3,D);wq(n3,D);

    wq(n2,D);wq(n1,D);wq(n2,D);wq(n3,B);wq(n3,D);

    wq(n6,C);wq(n3,C);wq(n2,C);wq(n1,D);wq(n1,D);

    wq(n1,D);wq(n2,D);wq(n3,D);wq(n2,C);S(C);S(D);
    //-----------------------------------------作者 ssw02 -----
    //----------C1----D0.5---------------------------------------4
    wq(n5,C);wq(n3,C);wq(n2,C);wq(n3,D);wq(n3,D);

    wq(n2,D);wq(n1,D);wq(n2,D);wq(n3,B);wq(n3,D);

    wq(n6,C);wq(n3,C);wq(n1,C);wq(n3,C);

    wq(n1,C);S(C);S(C);S(D);wq(n1,E);wq(l5,E);
    //----------------------------------------作者 ssw02 -----1
    //----------C1----D0.5---------------------------------------4
    wq(l6,375);wq(l6,375);wq(l5,D);wq(n1,375);wq(n1,E);S(D);wq(n1,E);wq(l5,E);

    wq(l6,375);wq(l6,375);wq(l5,D);wq(n1,375);wq(n3,E);S(D);wq(n1,E);wq(l5,E);

    wq(l6,375);wq(l6,D);wq(l6,E);wq(n5,D);wq(n1,375);wq(n1,D);wq(n1,E);wq(n2,D);

    wq(n1,375);wq(n1,E);S(E);wq(n1,E);wq(l6,D);wq(n3,C);S(D);wq(n1,E);wq(l5,E);

    wq(l6,375);wq(l6,375);wq(l5,D);wq(n1,375);wq(n1,E);S(D);wq(n1,E);wq(l5,E);

    wq(l6,375);wq(l6,375);wq(l5,D);wq(n3,375);wq(n1,E);S(D);wq(n1,E);wq(l5,E);

    wq(l6,375);wq(l6,D);wq(l6,E);wq(n5,D);wq(n1,375);wq(n1,D);wq(n1,E);wq(n2,D);

    wq(n1,375);wq(n1,D);wq(n3,375);wq(n1,C);S(C);


}
*/#include <cstdio>
#include <windows.h>
#define qdo 262 
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865
#define b(a,b) Beep(a,b)
int main(){int pai=600,ban=300;b(do,pai);b(re,pai);b(mi,pai);b(mi,pai);b(mi,ban);b(re,ban);b(do,ban);b(so,pai);Sleep(pai);b(la,pai);b(si,pai);b(do1,pai);b(do1,pai);b(si,ban);b(la,ban);b(so,ban);b(la,pai);b(so,pai);Sleep(pai);b(la,pai);b(si,pai);b(do1,pai);b(do1,pai);b(si,ban);b(la,ban);b(so,ban);b(la,pai);b(la,ban);b(so,ban);b(fa,ban);b(so,pai);b(fa,ban);b(mi,ban);b(re,ban);b(mi,pai<<1); Sleep(pai);b(do,pai);b(re,pai);b(mi,pai);b(mi,pai);b(mi,ban);b(re,ban);b(do,ban);b(so,pai);Sleep(pai);b(la,pai);b(si,pai);b(do1,pai);b(do1,pai);b(si,ban);b(la,ban);b(so,ban);b(la,pai);b(so,pai);Sleep(pai);b(la,pai);b(si,pai);b(do1,pai);b(do1,pai);b(si,ban);b(la,ban);b(so,ban);b(la,pai);b(la,ban);b(so,ban);b(fa,ban);b(so,pai);b(fa,ban);b(mi,ban);b(re,ban);b(do,pai<<1); 
}
