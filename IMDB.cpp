#include<bits/stdc++.h>
#include<math.h>
#include<iostream>
#include <fstream>
#include<string>
#include<iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

int u[51][61], n[9];
float m[61], m1[61], mn[4], r[51], ns[9];

void end(void){
    exit(0);
}

void bank(void){
    string s, s1;
    int  a[5], b=0, z, x, y;
    ifstream fin;
    fin.open("Ratings.txt");
    for (int q=0; q<100000; q++){
        getline(fin, s);
        for (int i=0; i<s.size(); i++){
            if (s[i]=='	'){
                a[b]=i;
                b++;
            }
        }
        b=0;
        s1= s.substr(0,a[0]);
        x= stoi(s1);
        s1= s.substr(a[0]+1,2);
        y= stoi(s1);
        s1= s.substr(a[1]+1,2);
        z= stoi(s1);
        u[x][y]= z;
    }
    for (int i=1; i<=50; i++){
        for (int j=1; j<=60; j++){
            if ((u[i][j]>10) || (u[i][j]<0)){
                u[i][j]=0;
            }
        }
    }
    fin.close();
}

void save_rating(string s1, string s2, string s3){
    string s, s4, s5, s6, s9;
    char c;
    int a[5], b=0;
    bool t=false;
    fstream fos;
    fstream fos1;
    fos.open("Ratings.txt", ios::in);
    fos1.open("Ratings2.txt", ios::out);
    while (getline(fos, s)){
        for (int i=0; i<s.size(); i++){
            if (s[i]=='	'){
                a[b]=i;
                b++;
            }
        }
        b=0;
        s4= s.substr(0,a[0]);
        s5= s.substr(a[0]+1,a[1]-a[0]-1);
        if ((s1==s4) && (s2==s5)){
            fos1 << s1 << '\t' << s2 << '\t' << s3 << endl;
            t=true;
        }
        else{
            fos1 << s << endl;
        }
    }
    getline(fos1, s9);
    fos.close();
    fos1.close();
    if (t==false){
        fos.open("Ratings.txt", ios::in | ios::app);
        if (s9!=s)
            fos << endl;
        fos << s1 << '\t' << s2 << '\t' << s3 << endl;
        fos.close();
    }
    else{
        fos.open("Ratings.txt", ios::out);
        fos1.open("Ratings2.txt", ios::in);
        while (getline(fos1, s)){
            fos << s << endl;
        }
        fos.close();
        fos1.close();
    }
    remove("Ratings2.txt");
}

void save_movie(string s1, string s2){
    string s, s3;
    char c;
    int a[6], b=0, d=0, a1;
    bool t=false;
    fstream fos;
    fos.open("Movies.txt", ios::in);
    while (getline(fos, s)){
        d++;
    }
    fos.close();
    d++;
    fos.open("Movies.txt", ios::app);
    fos << endl << d << '\t' << s1 << "\t\t" << s2;
    fos.close();
}

void remove_movie_name(string s1){
    string s, s2, s3, s4, s5, s6, s9;
    char c;
    int a[5], b=0;
    bool t=false;
    fstream fos;
    fstream fos1;
    fos.open("Movies.txt", ios::in);
    fos1.open("Movies2.txt", ios::out);
    while (getline(fos, s)){
        for (int i=0; i<s.size(); i++){
            if (s[i]=='	'){
                a[b]=i;
                b++;
            }
        }
        b=0;
        s4= s.substr(0,a[0]);
        s5= s.substr(a[0]+1,a[1]-a[0]-1);
        if (s1==s5){
            b=b;
        }
        else{
            fos1 << s << endl;
        }
    }
    fos.close();
    fos1.close();
        fos.open("Movies.txt", ios::out);
        fos1.open("Movies2.txt", ios::in);
        while (getline(fos1, s)){
            fos << s << endl;
        }
        fos.close();
        fos1.close();
    remove("Movies2.txt");
}

void remove_movie_id(string s1){
    string s, s2, s3, s4, s5, s6, s9;
    char c;
    int a[5], b=0;
    bool t=false;
    fstream fos;
    fstream fos1;
    fos.open("Movies.txt", ios::in);
    fos1.open("Movies2.txt", ios::out);
    while (getline(fos, s)){
        for (int i=0; i<s.size(); i++){
            if (s[i]=='	'){
                a[b]=i;
                b++;
            }
        }
        b=0;
        s4= s.substr(0,a[0]);
        s5= s.substr(a[0]+1,a[1]-a[0]-1);
        if (s1==s4){
            b=b;
        }
        else{
            fos1 << s << endl;
        }
    }
    fos.close();
    fos1.close();
        fos.open("Movies.txt", ios::out);
        fos1.open("Movies2.txt", ios::in);
        while (getline(fos1, s)){
            fos << s << endl;
        }
        fos.close();
        fos1.close();
    remove("Movies2.txt");
}

float just_do_it(string s1, string s2){
    string ss;
    int a, b, c=0;
    float sum=0, e=0, f=0, g=0;
    a= stoi(s1);
    b= stoi(s2);
    for (int i=1; i<=60; i++){
        if ((u[a][i]!=0) && (u[b][i]!=0)){
            e= e + (u[a][i] * u[b][i]);
            f= f + (u[a][i] * u[a][i]);
            g= g + (u[b][i] * u[b][i]);
        }
    }
    sum= e / ((pow(f, 0.5)) * (pow(e, 0.5)));
    return sum;
}

void just_do_it_2_electric_bogloo(string s1){
    int a, b, c=0;
    float sum=0, e=0, f=0, g=0;
    a= stoi(s1);
    for (int b=1; b<=50; b++){
        for (int i=1; i<=60; i++){
            if ((u[a][i]!=0) && (u[b][i]!=0)){
                e= e + (u[a][i] * u[b][i]);
                f= f + (u[a][i] * u[a][i]);
                g= g + (u[b][i] * u[b][i]);
            }
        }
        sum = e / ((pow(f, 0.5)) * (pow(e, 0.5)));
        r[b]= sum;
        e=0;
        g=0;
        f=0;
    }
    r[a]=0;
}

void sort_me_daddy(void){
    int a;
    float max1;
    for (int i=1; i<=8; i++){
        max1=0;
        for (int j=1; j<=50; j++){
            if (r[j]>max1){
                a=j;
                max1=r[j];
            }
        }
        r[a]= 0;
        n[i]= a;
        ns[i]= max1;
    }

}

void sort_me_daddy_2_electric_bogloo(void){
    int a;
    for (int i=1; i<=3; i++){
        int max=0;
        for (int j=1; j<=60; j++){
            if (m1[j]>max){
                a=j;
                max=m1[j];
            }
          //  cout << m1[j] << endl;
        }
        m1[a]= 0;
        mn[i]= a;
    }
}

void rate(string s2){
    string s, s1;
    int a[6], b=0, c=1, d, f;
    float sum1=0, sum2=0;
    for (int i=1; i<=60; i++){
        m[i]=0;
        m1[i]=0;
    }
    d= stoi (s2);
    while (c!=61){
        if (u[d][c]==0){
            for (int i=1; i<=8; i++){
                int k= n[i];
                sum1+= (u[k][c] * ns[i]);
                sum2+= ns[i];
            }
            m[c]= sum1 / (pow(sum2, 0.5));
            m1[c]= sum1 / (pow(sum2, 0.5));
        }
        c++;
    }
    sort_me_daddy_2_electric_bogloo();
}

int main_menu(void){
    int a;
    cout << "                                             MINI IMDB                                             " << endl;
    cout << "                                  ***********MAIN MENU***********                                  " << endl << endl;
    cout << "  1. Display movies" << endl;
    cout << "  2. Display ratings" << endl;
    cout << "  3. Display similarity between two users" << endl;
    cout << "  4. Generate recommendation" << endl;
    cout << "  5. Rate a movie" << endl;
    cout << "  6. Add/Remove a movie" << endl;
    cout << "  7. Exit" << endl << endl << endl;
    cout << "  Enter your choice: ";
    while (1==1){
        cin >> a;
        system("color 0F");
        cout << endl;
        if ( (a>=1) && (a<=7) )
            break;
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
    return (a);
}

int movies_menu(void){
    string s, s1;
    char c;
    int a[6], b=0;
    ifstream fin;
    fin.open("Movies.txt");
    cout << " --------------" << endl;
    cout << " Display Movies" << endl;
    cout << " --------------" << endl;
    cout << " Movie id\tMovie name\t\t\t\t\tYear" << endl;
    cout << " --------\t----------\t\t\t\t\t----" << endl;
    while (getline(fin, s)){
        for (int j=0; j<s.size(); j++){
            if (s[j]=='	'){
                a[b]=j;
                b++;
            }
        }
        b=0;
        s1= s.substr(0,a[0]);
        cout  << ' ' << s1;
        s1.clear();
        s1= s.substr(a[0],a[1]-a[0]);
        cout << "\t" << s1;
        s1.clear();
        s1= s.substr(a[1],a[2]-a[1]);
        cout << setw(46-(a[1]-a[0]));
        cout << s1 << endl;
        s1.clear();
    }
    cout << " Press 'm' to Main menu, and 'q' to Quit ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='m'){
            return (1);
        }
        else if (c=='q'){
            end();
        }
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
    fin.close();
}

int rating_menu(void){
    string s, s1, s2;
    int a[6], b=0, a1;
    char c;
    ifstream fin;
    fin.open("Ratings.txt");
    cout << " ---------------" << endl;
    cout << " Display Ratings" << endl;
    cout << " ---------------" << endl << endl;
    cout << " Enter user id: ";
    while (1==1){
        cin >> s2;
        a1= stoi (s2);
        system("color 0F");
        cout << endl;
        if ((a1>=1) && (a1<=50))
            break;
        else{
            system("color 0c");
            cout << "This user id does not exist. Try again: ";
        }
    }
    cout << endl << " Ratings of user " << s2 << " are:" << endl;
    cout << " Movie id \t Rating" << endl;
    cout << " -------- \t ------" << endl;
    while (getline(fin, s)){
        for (int i=0; i<s.size(); i++){
            if (s[i]=='	'){
                a[b]=i;
                b++;
            }
        }
        b=0;
        s1= s.substr(0,a[0]);
        if (s1==s2){
            s1= s.substr(a[0]+1,a[1]-a[0]);
            cout  << s1;
            s1.clear();
            s1= s.substr(a[1]+1,a[2]-a[1]);
            cout << "\t " << s1 << endl;
        }
    }
    cout << " Press 'r' to Retry,'m' to Main menu,and 'q' to Quit ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='m'){
            return (1);
        }
        else if (c=='q'){
            end();
        }
        else if (c=='r'){
            return (2);
        }
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
    fin.close();
}

int sim_menu(void){
    string s, s1, s2, s4;
    int a[6], b=0, d=0, a1;
    float f;
    char c;
    ifstream fin;
    fin.open("Ratings.txt");
    cout << " ---------------" << endl;
    cout << " Display Ratings" << endl;
    cout << " ---------------" << endl << endl;
    cout << " Enter first user id: ";
    while (1==1){
        cin >> s2;
        system("color 0F");
        cout << endl;
        a1= stoi (s2);
        if ((a1>=1) && (a1<=50))
            break;
        else{
            system("color 0c");
            cout << " This user id does not exist. Try again: ";
        }
    }
    cout << endl;
    cout << " Enter second user id: ";
    while (1==1){
        cin >> s4;
        system("color 0F");
        cout << endl;
        a1= stoi (s2);
        if ((a1>=1) && (a1<=50))
            break;
        else{
            system("color 0c");
            cout << " This user id does not exist. Try again: ";
        }
    }
    f= just_do_it(s2, s4);
    cout << "Similarity between user" << s1 << " and user" << s2 << " is: " << f << endl << endl;
    cout << " Press 'r' to Retry,'m' to Main menu,and 'q' to Quit ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='m'){
            return (1);
        }
        else if (c=='q'){
            end();
        }
        else if (c=='r'){
            return (2);
        }
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
    fin.close();
}

int recommendation_menu(void){
    for (int i=0; i<51; i++){
        r[i]=0;
    }
    for (int i=0; i<61; i++){
        m[i]=0;
        m1[i]=0;
    }
    for (int i=0; i<10; i++){
        m[i]=0;
        m1[i]=0;
    }
    string s, s1, s2;
    char c;
    int b=0, a[7], d, d1, a1;
    ifstream fin;
    fin.open("Ratings.txt");
    cout << " -----------------------" << endl;
    cout << " Generate Recommendation" << endl;
    cout << " -----------------------" << endl << endl;
    cout << " Enter user id: ";
    while (1==1){
        cin >> s2;
        a1= stoi (s2);
        system("color 0F");
        cout << endl;
        if (((a1>=1)) && (a1<=50) )
            break;
        else{
            system("color 0c");
            cout << " This user id does not exist. Try again: ";
        }
    }
    cout << endl;
    cout << " Top-3 recommendation for user " << s2 << " are:" << endl << endl;
    cout << " Movie id\tMovie name\t\t\t\t\tYear\t\t\tPredicted rating" << endl;
    cout << " --------\t----------\t\t\t\t\t----\t\t\t----------------" << endl;
    just_do_it_2_electric_bogloo(s2);
    sort_me_daddy();
    rate(s2);
    for (int j=1; j<=3; j++){
        cout << ' ' << mn[j];
        ifstream fin;
        fin.open("Movies.txt");
        for (int i=1; i<61; i++){
        getline(fin, s);
        for (int ii=0; ii<s.size(); ii++){
            if (s[ii]=='	'){
                a[b]=ii;
                b++;
            }
        }
        b=0;
        s1= s.substr(0,a[0]);
        d= stoi (s1);
        if (d==mn[j]){
            s1.clear();
            s1= s.substr(a[0],a[1]-a[0]);
            cout << "\t" << s1;
            s1.clear();
            s1= s.substr(a[1],a[2]-a[1]);
            cout << setw(46-(a[1]-a[0]));
            cout << s1 ;
            int k=mn[j];
            cout << "\t\t\t" << m[k] << endl;
            s1.clear();
        }
        }
    }
    cout << endl;
    e9:
    cout << " ====What do you want to do?====" << endl;
    cout << " a.Display all predictions for this user" << endl;
    cout << " b.Retry" << endl;
    cout << " c.back to menu" << endl;
    cout << " d.exit" << endl;
    cout << " Your choice: ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='a'){
            cout << endl << endl;
            cout << " Prediction of unseen movies by user" << s2 << ':' << endl << endl;
            cout << " Movie id\tMovie name\t\t\t\t\tYear\t\t\tPredicted rating" << endl;
            cout << " --------\t----------\t\t\t\t\t----\t\t\t----------------" << endl;
            ifstream fin;
            fin.open("Movies.txt");
                for (int i=1; i<61; i++){
                    getline(fin, s);
                    for (int ii=0; ii<s.size(); ii++){
                        if (s[ii]=='	'){
                            a[b]=ii;
                            b++;
                        }
                    }
                    b=0;
                    s1= s.substr(0,a[0]);
                    d= stoi (s1);
                    if (u[a1][d]==0){
                        cout << ' ' << s1;
                        s1.clear();
                        s1= s.substr(a[0],a[1]-a[0]);
                        cout << "\t" << s1;
                        s1.clear();
                        s1= s.substr(a[1],a[2]-a[1]);
                        cout << setw(46-(a[1]-a[0]));
                        cout << s1 ;
                        cout << "\t\t\t" << m[i] << endl;
                        s1.clear();
                    }
                }
            cout << endl;
            goto e9;
        }
        else if (c=='b'){
            cout << 'b';
            return 2;
        }
        else if (c=='c'){
            cout << 'c';
            return 1;
        }
        else if (c=='d'){
            cout << 'd';
            end();
        }
        else{
            cout << endl;
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
}

int rate_menu(void){
    string s, s1, s2, s3;
    int a, a1, a2, a3;
    char c, c1;
    system("color 0F");
    cout << " ------------" << endl;
    cout << " Rate a movie" << endl;
    cout << " ------------" << endl << endl;
    cout << " Enter the Information Below" << endl;
    cout << " = = = = = = = = = = = = = =" << endl;
    cout << " User ID: ";
    cin >> s1;
    cout << endl;
    cout << " Movie ID: ";
    cin >> s2;
    cout << endl;
    cout << " Rating (1-5): ";
    cin >> s3;
    cout << endl;
    cout << " = = = = = = = = = = = = = =" << endl;
    cout << " Do you want to save (Y/N)? ";
    cin >> c1;
    cout << endl;
    if (c1=='Y'){
        a1= stoi (s1);
        a2= stoi (s2);
        a3= stoi (s3);
        if ((a1<1) || (a1>50)){
            system("color 0c");
            cout << " This user id does not exist" << endl << endl;
        }
        else if ((a2<1) || (a2>60)){
            system("color 0c");
            cout << " This movie id does not exist" << endl << endl;
        }
        else if ((a3<1) || (a3>5)){
            system("color 0c");
            cout << " This rating is not valid (only between 1-5)" << endl << endl;
        }
        else{
            save_rating(s1, s2, s3);
        }
    }
    else if (c1=='N')
        a=0;
    else{
        system("color 0c");
        cout << " Invalid option, press 'r' to continue" << endl;
    }
    cout << " Press 'r' to Retry,'m' to Main menu,and 'q' to Quit ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='m'){
            return (1);
        }
        else if (c=='q'){
            end();
        }
        else if (c=='r'){
            return (2);
        }
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
}

int add_menu(void){
    string s, s1, s2, s3;
    char c;
    int a[6], b=0;
    bool exist=false;
    ifstream fin;
    system("color 0F");
    fin.open("Movies.txt");
    cout << " ---------------" << endl;
    cout << " Add a new movie" << endl;
    cout << " ---------------" << endl << endl;
    cout << " Enter the Information Below" << endl;
    cout << " = = = = = = = = = = = = = =" << endl;
    cout << " Name: ";
    cin >> s1;
    cout << " Year: ";
    cin >> s2;
    cout << " = = = = = = = = = = = = = =" << endl << endl;
    cout << " Do you want to save(Y/N)? ";
    cin >> c;
    cout << endl;
    if (c=='Y'){
        for (int i=0; i<60; i++){
            getline(fin, s);
            for (int j=0; j<s.size(); j++){
                if (s[j]=='	'){
                    a[b]=j;
                    b++;
                }
            }
            b=0;
            s3= s.substr(a[0]+1,a[1]-a[0]-1);
            if (s3==s1){
                exist=true;
            }
        }
    }
    if (exist==true){
        system("color 0c");
        cout << " This movie already exist" << endl;
    }
    else{
        save_movie(s1, s2);
        cout << " The record was successfully saved." << endl << endl;
    }
    cout << " Press 'r' to Retry, 'p' to Previous, m' to Main menu,and 'q' to Quit ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='m'){
            return (1);
        }
        else if (c=='q'){
            end();
        }
        else if (c=='r'){
            return (2);
        }
        else if (c=='p'){
            return 3;
        }
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
}

int remove_menu(void){
    string s, s1, s2, s3;
    char c, c2;
    int a[6], b=0;
    bool exist=false;
    ifstream fin;
    system("color 0F");
    fin.open("Movies.txt");
    cout << " --------------" << endl;
    cout << " Remove a movie" << endl;
    cout << " --------------" << endl << endl;
    cout << " = = = Remove by name or ID? = = =" << endl;
    cout << " a.By name " << endl;
    cout << " b.By ID " << endl;
    cout << " Your choice: ";
    cin >> c2;
    cout << endl;
    if (c2=='a'){
        cout << " Enter the name of movie: ";
        cin >> s1;
        cout << endl;
        cout << " Are you sure you want to delete '" << s1 << "'(Y/N)? ";
        cin >> c;
        if (c=='Y'){
            while (getline(fin, s)){
                for (int j=0; j<s.size(); j++){
                    if (s[j]=='	'){
                        a[b]=j;
                        b++;
                    }
                }
                b=0;
                s3= s.substr(a[0]+1,a[1]-a[0]-1);
                if (s3==s1){
                    exist=true;
                }
            }
            if (exist==false){
                system("color 0c");
                cout << " This movie does not exist" << endl;
            }
            else{
                remove_movie_name(s1);
                cout << " The record was successfully saved." << endl << endl;
            }
        }
        cout << endl;
    }
    else if (c2=='b'){
        cout << " Enter movie ID: ";
        cin >> s1;
        cout << endl;
        cout << " Are you sure you want to delete 'movie" << s1 << "'(Y/N)? ";
        cin >> c;
        if (c=='Y'){
            while (getline(fin, s)){
                for (int j=0; j<s.size(); j++){
                    if (s[j]=='	'){
                        a[b]=j;
                        b++;
                    }
                }
                b=0;
                s3= s.substr(0,a[0]);
                if (s3==s1){
                    exist=true;
                }
            }
            if (exist==false){
                system("color 0c");
                cout << " This movie does not exist" << endl;
            }
            else{
                remove_movie_id(s1);
                cout << " The record was successfully saved." << endl << endl;
            }
        }
        cout << endl;
    }
    else{
        system("color 0F");
        cout << " This option is invalid." << endl;
    }
    cout << " Press 'r' to Retry, 'p' to Previous, m' to Main menu,and 'q' to Quit ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='m'){
            return (1);
        }
        else if (c=='q'){
            end();
        }
        else if (c=='r'){
            return (2);
        }
        else if (c=='p'){
            return 3;
        }
        else{
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
}

int add_remove_movie_menu(void){
    char c;
    int a;
    cout << " ------------------" << endl;
    cout << " Add/Remove a movie" << endl;
    cout << " ------------------" << endl << endl;
    cout << " = = = What do you want to do? = = =" << endl;
    cout << " a.Add a movie" << endl;
    cout << " b.Remove a movie" << endl;
    cout << " c.Back to main menu" << endl;
    cout << " a.Exit" << endl;
    cout << " Your choice: ";
    while (1==1){
        cin >> c;
        system("color 0F");
        if (c=='a'){
            cout << 'a';
            e6:
                system("CLS");
                a=add_menu();
                if (a==2)
                    goto e6;
                else if (a==3)
                    return 3;
                else
                    return 1;
        }
        else if (c=='b'){
            cout << 'b';
            e7:
                system("CLS");
                a=remove_menu();
                if (a==2)
                    goto e7;
                else if (a==3){
                    return 3;
                }
                else
                    return 1;
        }
        else if (c=='c'){
            cout << 'c';
            return 1;
        }
        else if (c=='d'){
            cout << 'd';
            end();
        }
        else{
            cout << endl;
            system("color 0c");
            cout << "This option is invalid. Try again: ";
        }
    }
}

int main(){
    int a, b;
    bank();
    a= main_menu();
    system("CLS");
    e1:
        switch (a){
        case 1:
            system("CLS");
            b=movies_menu();
            system("CLS");
            a= main_menu();
            goto e1;
            break;
        case 2:
            e2:
                system("CLS");
                b=rating_menu();
                if (b==1){
                    system("CLS");
                    a= main_menu();
                    goto e1;
                }
                else{
                    system("CLS");
                    goto e2;
                }
                break;
        case 3:
            e3:
                system("CLS");
                b=sim_menu();
                if (b==1){
                    system("CLS");
                    a= main_menu();
                    goto e1;
                }
                else{
                    system("CLS");
                    goto e3;
                }
                break;
        case 4:
            e4:
                system("CLS");
                b=recommendation_menu();
                if (b==1){
                    system("CLS");
                    a= main_menu();
                    goto e1;
                }
                else{
                    system("CLS");
                    goto e4;
                }
                break;
        case 5:
            e5:
                system("CLS");
                b=rate_menu();
                if (b==1){
                    system("CLS");
                    a= main_menu();
                    goto e1;
                }
                else{
                    system("CLS");
                    goto e5;
                }
                break;
        case 6:
            e8:
                system("CLS");
                b=add_remove_movie_menu();
                if (b==1){
                    system("CLS");
                    a= main_menu();
                    goto e1;
                }
                else if (b==3){
                    system("CLS");
                    goto e8;
                }
                break;
        case 7:
            end();
            break;
    }
}
