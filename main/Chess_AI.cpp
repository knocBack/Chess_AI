#include <bits/stdc++.h>
#include <wchar.h>
#include <locale.h>
using namespace std;

#define TL 201    // ╔ Top Left
#define TR 187    // ╗ Top R8
#define BL 200    // ╚ Bottom Left
#define BR 188    // ╝ Bottom R8
#define TM 209    // ╤ Top Mid
#define TS 196    // ─ Top Staright
#define LM 199    // ╟ Left Mid
#define Verti 186 // ║ Vertical - Border
#define LS 179    // │ Left Straight
#define RM 182    // ╢ Right Mid
#define RS LS     // │ Right Straight
#define Hori 205  // ═ Horizontal - Border
#define BM 207    // ╧ Bottom Mid
#define BS TS     // ─ Bottom Straight
#define PLUS 197  // ┼ MID

#define black 219 // █ black square!
#define white 32  // ' ' white space!

// white - pieces
#define W_N 78  // N - white knight
#define W_B 66  // B - white bishop
#define W_R 82  // R - white rook
#define W_K 75  // K - white king
#define W_Q 81  // Q - white qween
#define W_S 80  // P - white pawn

// black - pieces
#define B_N 110  // n - black knight
#define B_B 98   // b - black bishop
#define B_R 114  // r - black rook
#define B_K 107  // k - black king
#define B_Q 113  // q - black qween
#define B_S 112  // p - black pawn


class Board {
private:
    char Pieces[8][8] = {
        {B_R,B_N,B_B,B_Q,B_K,B_B,B_N,B_R},
        {B_S,B_S,B_S,B_S,B_S,B_S,B_S,B_S},
        {' ','#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ','#',' ','#',' '},
        {' ','#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ','#',' ','#',' '},
        {W_S,W_S,W_S,W_S,W_S,W_S,W_S,W_S},
        {W_R,W_N,W_B,W_Q,W_K,W_B,W_N,W_R}
    };
    bool Player = true;
    char Piece = W_S;
    int Row=0,Col=0;
    void printTop(){
        int x='a';
        printf("\\ ");
        for(int i=2;i<19;i++){
            if(i&1){printf(" %c ",x);x++;}
            else printf(" ");
        }
        printf("\n  %c", TL);
        for (int i = 3; i < 18; i++) {
            if (i & 1)printf("%c%c%c", Hori,Hori,Hori);
            else printf("%c", TM);
        }
        printf("%c\n", TR);
    }
    void printBottom(){
        printf("\n  %c", BL);
        for (int i = 3; i < 18; i++) {
            if (i & 1)printf("%c%c%c", Hori,Hori,Hori);
            else printf("%c", BM);
        }
        printf("%c\n", BR);
    }
    void printPieces(){
        int a=0,b=0,i=0,j=0;
        for(j=0;j<8;j++){
            printf("%d %c",8-j,Verti);
            for(i=3;i<18;i++){
                if(i%2==1){printf(" %c",Pieces[a][b]);b++;}
                else if(i%2==0)printf("%c%c",white,LS);
            }
            printf(" %c",Verti);
            if(a!=7){
                printf("\n  %c",LM);
                for(i=1;i<16;i++){
                    if(i&1)printf("%c%c%c",BS,BS,BS);
                    else printf("%c",PLUS);
                    }
                printf("%c\n",RM);
            }
            else{
                printBottom();
            }
            a++;b=0;
        }
    }
    bool isOnBoard(char col, char row){
        //column : col --> 'a' - 'h'
        //row : row --> '1' - '8'
        if((col>='a'&&col<='h')&&(row>='1'&&row<='8')){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(Pieces[i][j]==Piece){
                        Row = i;Col = j;
                        return true;
                    }
                }
            }
        }
        return false;        
    }
    bool isValidPiece(){
        //player = 1 => white!
        //player = 0 => black!
        bool isValidPiece = false;
        if(Player){
            switch(Piece){
                case 'R':
                case 'N':
                case 'K':
                case 'Q':
                case 'B':
                case 'P':
                    isValidPiece = true;
                    break;
            }
        }
        else{
            switch(Piece){
                case 'r':
                case 'n':
                case 'k':
                case 'q':
                case 'b':
                case 'p':
                    isValidPiece = true;
                    break;
            }
        }
        return isValidPiece;
    }
    
public:
    void print_table(){
        printTop();
        printPieces();
    }
    bool validateMove(string move){
        int len = move.length();
        bool valid = false;
        if(len > 1 && len < 6){
            switch (len){
            case 5:
                if(move=="o-o-o\0")valid = true;
                else valid = false;
                break;
            case 2:
                if((move[0]>='a'&&move[0]<='h')&&(move[1]>='1'&&move[1]<='8'))valid = true;
                else valid = false;
                break;
            case 3:
                if((move[1]>='a'&&move[1]<='h')&&(move[2]>='1'&&move[2]<='8'))
                break;
            }
        }
    }
    bool place_move(char piece, char col, char row){
        Piece = piece;
        if (isValidPiece() && isOnBoard(col, row)){
            
            Player = !Player;
            return true;
        }
        return false;
    }
    bool place_capture(){
        
    }
};

int main()
{
    Board board;
    board.print_table();
    string move,prev_move;prev_move = move;
    cout<<"what is your move: ";
    cin>>move;
    
    cout<<"your move is invalid!"<<'\n';
}

//input: movement!
/*
    R , N , B , Q , K 
    r , n , b , q , k

valid moves:
    Ka3     Bc5     Qb1     Nh4     h2
capturing:  Bxc6    Qxb1    Nxh4    gxh3
if two rooks can reach the same position! 
  ->Ra4 , Rh4 are positions of two rooks!
    rook1 : a4 -> d4 ! it is representated as Rad4!
  ->Ra1 , Ra8 are positions of two rooks!
    rook1 : a1 -> a4 ! it is representated as R1a4!

castling:   short - o-o
            long - o-o-o

*/