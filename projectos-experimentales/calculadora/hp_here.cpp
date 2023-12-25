#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
#include<iomanip.h>

#define FALSE 0
#define TRUE !FALSE
#define ESC '\033'

struct Nodo {
    double value;
    Nodo* sig;
    char tag[10];
};

class Hp {
protected:
    Nodo* primero;

public:
    Hp();
    ~Hp();
    void push(double);
    double pop();
    void drop();
    int listaVacia();
    void screen();
};

class memHp : public Hp {
public:
    void store(double);
    double rcl();
    void del();
    void display();
    void nextview();
};

double valor(double op1, double op2, char c);
double valor(double op2, char c);
double concate(char s1[], char s2[], int MAX);
void lineas_vert(int fila_1, int fila_2, int col, char car);
void lineas_hor(int col_1, int col_2, int filas, char car);
double a_numer2(char s[], int m);
int is_command(char c);
int is_editor(char c);
int is_symbol(char c);
void casehp();
void timer();
void error(char c);

Hp::Hp() {
    primero = NULL;
}

Hp::~Hp() {
    Nodo* p;
    Nodo* temp;
    p = primero;
    while (p != NULL) {
        temp = p->sig;
        delete p;
        p = temp;
    }
}

void Hp::push(double carac) {
    Nodo* p;
    p = new Nodo;
    p->value = carac;
    p->sig = primero;
    primero = p;
}

double Hp::pop() {
    if (!listaVacia()) {
        Nodo* p = primero;
        primero = p->sig;
        return (p->value);
    }
    return 0;
}

void Hp::drop() {
    if (!listaVacia()) {
        Nodo* p = primero;
        primero = p->sig;
    }
}

int Hp::listaVacia() {
    if (primero == NULL)
        return TRUE;
    else
        return FALSE;
}

void Hp::screen() {
    casehp();
    Nodo* p;
    int acu = 0;
    p = primero;
    if (!listaVacia()) {
        while (p != NULL) {
            p = p->sig;
            acu++;
        }
        p = primero;
        int fila = 14;
        for (int i = 1; i <= acu; i++) {
            gotoxy(33, fila--);
            if (fila >= 5) {
                cout.fill(' ');
                cout << setw(10) << setprecision(6) << p->value;
            } else {
                gotoxy(18, 6);
                cout << "->•••";
            }
            p = p->sig;
        }
    }
}

void memHp::store(double op2) {
    Nodo* p;
    p = new Nodo;
    p->value = op2;
    gotoxy(18, 13);
    cout << "Mode Store/ ";
    gotoxy(18, 14);
    cout << "Name var?: ";
    cin >> p->tag;
    p->sig = primero;
    primero = p;
}

double memHp::rcl() {
    char s[10];
    int encuentra = 0;
    gotoxy(18, 13);
    cout << "Mode Rcl/ ";
    gotoxy(18, 14);
    cout << "Name var?: ";
    cin >> s;
    Nodo* p = primero;
    if (listaVacia())
        error(' ');
    else {
        while (!encuentra && p != NULL) {
            if (strcmp(p->tag, s) == 0)
                encuentra = 1;
            else
                p = p->sig;
        }
    }
    if (encuentra)
        return p->value;
    else
        return 0;
}

void memHp::del() {
    int encuentra = FALSE;
    Nodo* p;
    Nodo* antP;
    p = primero;
    antP = NULL;
    char s[10];
    gotoxy(18, 13);
    cout << "Mode Del/ ";
    gotoxy(18, 14);
    cout << "Name var?: ";
    cin >> s;
    if (listaVacia())
        error(' ');
    else {
        while (!encuentra && p != NULL) {
            if (strcmp(p->tag, s) == 0)
                encuentra = TRUE;
            else {
                antP = p;
                p = p->sig;
            }
        }
        if (encuentra) {
            if (antP == NULL) {
                primero = p->sig;
                delete p;
            } else {
                antP->sig = p->sig;
                delete p;
            }
        } else
            error(' ');
    }
}

void memHp::display() {
    Nodo* p;
    p = primero;
    int x = 0;
    gotoxy(13, 16);
    if (!listaVacia()) {
        while (p != NULL) {
            if (x <= 46)
                cout << p->tag << "|";
            x = wherex();
            p = p->sig;
        }
    }
}

void memHp::nextview() {
    Nodo* p;
    p = primero;
    int x = 0;
    gotoxy(13, 16);
    clreol();
    if (!listaVacia()) {
        while (p != NULL) {
            if (x < 46)
                printf("%s|", p->tag);
            else {
                gotoxy(18, 13);
                cout << "press key";
                getch();
                gotoxy(13, 16);
                clreol();
                printf("%s|", p->tag);
            }
            x = wherex();
            p = p->sig;
        }
    }
}

double valor(double op1, double op2, char c) {
    double y;
    switch (c) {
        case '+':
            y = (op1 + op2);
            break;
        case '-':
            y = (op1 - op2);
            break;
        case '*':
            y = (op1 * op2);
            break;
        case '/':
            if (op2 != 0)
                y = (op1 / op2);
            else {
                error(c);
                y = 0;
            }
            break;
        case '^':
            y = pow(op1, op2);
            break;
        default:
            break;
    }
    return y;
}

double valor(double op2, char c) {
    double y = 1;
    switch (c) {
        case '!':
            int k;
            for (k = 1; k <= op2; k++)

 {
                y *= k;
            }
            break;
        case 'c':
            y = cos(op2 * M_PI / 180);
            break;
        case 't':
            y = tan(op2 * M_PI / 180);
            break;
        case 's':
            y = sin(op2 * M_PI / 180);
            break;
        case 'i':
            if (op2 != 0)
                y = 1 / op2;
            else
                error('/');
            break;
        case 'b':
            y = -op2;
            break;
        case 'r':
            y = op2 * op2;
            break;
        case 'C':
            y = pow(op2, 2) * M_PI;
            break;
        default:
            break;
    }
    return y;
}

double concate(char s1[], char s2[], int MAX) {
    int k = MAX, i = 0, j = 0;
    for (k; k <= MAX * 2 - 1; k++) {
        s1[++j] = s2[i++];
    }
    return (a_numer2(s1, MAX + 1));
}

double a_numer2(char s[], int m) {
    int i = 0, k = 0, f = 1;
    char ch;
    double num, acu = 0, deci = 0, factor;
    while (i < m && s[i] != '.') {
        ch = s[i];
        num = ch - '0';
        acu = acu * 10 + num;
        i++;
        if (s[i] == '-' && i == (m - 1)) {
            f = -f;
            m--;
        }
    }
    if (s[i++] == '.') {
        while (i < m && s[i] != '-') {
            ch = s[i];
            num = ch - '0';
            deci = deci * 10 + num;
            i++;
            k++;
            if (s[i] == '.')
                error('.');
        }
        if (s[i] == '-' && i == (m - 1))
            f = -f;
        factor = pow(10, k);
        deci = deci / (double(factor));
        acu = (acu + deci);
    }
    return (acu * f);
}

int is_command(char c) {
    char s[] = "+-*/^sd\be!wct\rirCbum";
    int i = 0;
    while (s[i] != '\0')
        if (c == s[i++])
            return TRUE;
    return FALSE;
}

int is_editor(char c) {
    char s[] = "wd\be\ru";
    int i = 0;
    while (s[i] != '\0')
        if (c == s[i++])
            return TRUE;
    return FALSE;
}

int is_symbol(char c) {
    char s[] = "!sctiCbrm";
    int i = 0;
    while (s[i] != '\0')
        if (c == s[i++])
            return TRUE;
    return FALSE;
}

void casehp() {
    clrscr();
    int j = 9;
    lineas_vert(3, 15, 15, '|');
    lineas_vert(3, 15, 45, '|');
    lineas_hor(14, 46, 17, '*');
    lineas_hor(15, 45, 15, '_');
    lineas_hor(15, 45, 5, '_');
    lineas_hor(15, 45, 2, '_');
    lineas_hor(15, 45, 1, '_');
    lineas_hor(14, 46, 20, '*');
    gotoxy(17, 3);
    cout << "hp 48GX";
    gotoxy(12, 18);
    cout << "Edit[e]  Del[d]  Swap[w]  Drop[<-]Undo[u] ";
    gotoxy(13, 19);
    cout << "[ms_tore]    [mr_cl]    [md_el][mv_iew]";
    gotoxy(13, 21);
    cout << "  sin[s]  cos[c]  tan[t]  fact[!]";
    gotoxy(13, 22);
    cout << "      1/x[i]  x²[r]  A_Circ[C]    ±[b]";
    for (int k = 6; k <= 14; k++) {
        gotoxy(16, k);
        cout << j << ":";
        j--;
    }
    timer();
    gotoxy(18, 14);
}

void lineas_vert(int fila_1, int fila_2, int col, char car) {
    for (int rows = fila_1; rows <= fila_2; rows++) {
        gotoxy(col, rows);
        cout << car;
    }
}

void lineas_hor(int col_1, int col_2, int filas, char car) {
    for (int col = col_1; col <= col_2; col++) {
        gotoxy(col, filas);
        cout << car;
    }
}

void timer(void) {
    char datebuf[9];
    char timebuf[9];
    _strdate(datebuf);
    _strtime(timebuf);
    gotoxy(28, 4);
    printf("%s %s", datebuf, timebuf);
}

void error(char c) {
    gotoxy(18, 6);
    cout << c << "\a Error:";
    switch (c) {
        case '/':
            gotoxy(18, 7);
            cout << "Infinitive Result";
            break;
        case '.':
            gotoxy(18, 7);
            cout << "Invalid Sintaxis";
            break;
        default:
            gotoxy(18, 7);
            cout << "Too Few Arguments";
    }
    getch();
}

void main() {
    char c, t[10], s[15];
    int k;
    double op1, op2, op3, x, y;
    Hp heap;
    memHp memo;
    casehp();
    c = getch();
    while (c != ESC) {
        t[0] = c;
        if (!is_command(c)) {
            gotoxy(18, 14);
            putchar(c);
            gets(s);
            k = strlen(s);
            x = concate(t, s, k);
            heap.push(x);
            heap.screen();
            memo.display();
        } else {
            if (!is_editor(c)) {
                if (!is_symbol(c)) {
                    op2 = heap.pop();
                    op1 = heap.pop();
                    y = valor(op1, op2, c);
                    heap.push(y);
                    heap.screen();
                    memo.display();
                } else {
                    if (c != 'm') {
                        op2 = heap.pop();
                        y = valor(op2, c);
                        heap.push(y);
                        heap.screen();
                        memo.display();
                    } else {
                        putchar(c);
                        c = getch();
                        switch (c) {
                            case 's':
            op2 = heap.pop();  // store memory    
            memo.store(op2);    
            heap.screen();    
            memo.display();    
            break;
        case 'r':
            op3 = memo.rcl();    // recall memory    
            heap.push(op3);    
            heap.screen();    
            memo.display();    
            break;
        case 'd':
            memo.del(); // delete nodo memory    
            heap.screen();    
            memo.display();    
            break;
        case 'v':
            // nextview    
            heap.screen();    
            memo.display();        
            memo.nextview();    
            break;
        default:  
            error(c);
    } 
}
else {
    switch (c) {
        // acceso a menucommand_edit
        case 'w':  
            // swap
            op1 = heap.pop();
            op2 = heap.pop();
            heap.push(op1);
            heap.push(op2);
            heap.screen();
            memo.display();
            break;
        case '\b': 
            // drop
            op3 = heap.pop();
            heap.screen();
            memo.display();
            break;
        case 'd': 
            // delete
            while (!heap.listaVacia()) {
                op2 = heap.pop();
            }
            heap.screen();
            memo.display();
            break;
        case 'e':
            // edit
            op2 = heap.pop();
            heap.screen();
            memo.display();
            gotoxy(18, 14);
            cout << op2;
            cout << "    ";
            break;
        case '\r':
            // enter
            op2 = heap.pop();
            heap.push(op2);
            heap.push(op2);
            heap.screen();
            memo.display();
            break;
        case 'u':
            // undo
            heap.push(op3);
            heap.screen();
            memo.display();
            break;
    }
}
gotoxy(18, 14);  
c = getch();
}
/*************verifica si el caracter es operador******************/
int is_command(char c) {
    char s[] = "+-*/^sd\be!wct\rirCbum";
    int i = 0;
    while (s[i] != '\0') {
        if (c == s[i++]) {
            return TRUE;
        }
    }
    return FALSE;
}

int is_editor(char c) {
    char s[] = "wd\be\ru";
    int i = 0;
    while (s[i] != '\0') {
        if (c == s[i++]) {
            return TRUE;
        }
    }
    return FALSE;
}

int is_symbol(char c) {
    char s[] = "!sctiCbrm";
    int i = 0;
    while (s[i] != '\0') {
        if (c == s[i++]) {
            return TRUE;
        }
    }
    return FALSE;
}

/********genera marco de calculadora*********/
void casehp() {
    clrscr();
    int j = 9;
    lineas_vert(3, 15, 15, '|');
    lineas_vert(3, 15, 45, '|');
    lineas_hor(14, 46, 17, '*');
    lineas_hor(15, 45, 15, '_');
    lineas_hor(15, 45, 5, '_');
    lineas_hor(15, 45, 2, '_');
    lineas_hor(15, 45, 1, '_');
    lineas_hor(14, 46, 20, '*');
    gotoxy(17, 3);
    cout << "hp 48GX";
    gotoxy(12, 18);
    cout << "Edit[e]  Del[d]  Swap[w]  Drop[<-]Undo[u] ";
    gotoxy(13, 19);
    cout << "[ms_tore]    [mr_cl]    [md_el][mv_iew]";
    gotoxy(13, 21);
    cout << "  sin[s]  cos[c]  tan[t]  fact[!]";
    gotoxy(13, 22);
    cout << "      1/x[i]  x²[r]  A_Circ[C]    ±[b]";
    for (int k = 6; k <= 14; k++) {
        gotoxy(16, k);
        cout << j << ":";
        j--;
    }
    timer();
    gotoxy(18, 14);
}

void lineas_vert(int fila_1, int fila_2, int col, char car) {
    for (int rows = fila_1; rows <= fila_2; rows++) {
        gotoxy(col, rows);
        cout << car;
    }
}

void lineas_hor(int col_1, int col_2, int filas, char car) {
    for (int col = col_1; col <= col_2; col++) {
        gotoxy(col, filas);
        cout << car;
    }
}

/**********genera reloj de calculadora***********/
void timer(void) {
    char datebuf[9];
    char timebuf[9];
    _strdate(datebuf);
    _strtime(timebuf);
    gotoxy(28, 4);
    printf("%s %s", datebuf, timebuf);
}

/***funcion para convertir caracteres a números***/
double concate(char s1[], char s2[], int MAX) {
    int k = MAX, i = 0, j = 0;
    for (k; k <= MAX * 2 - 1; k++) {
        s1[++j] = s2[i++];
    }
    return (a_numer2(s1, MAX + 1));
}

double a_numer2(char s[], int m) {
    int i = 0, k = 0, f = 1;
    char ch;
    double num, acu = 0, deci = 0, factor;
    while (i < m && s[i] != '.') {
        ch = s[i];
        num = ch - '0';
        acu = acu * 10 + num;
        i++;
        if (s[i] == '-' && i == (m - 1)) {
            f = -f;
            m--;
        }
    }
    if (s[i++] == '.') {
        while (i < m && s[i] != '-') {
            ch = s[i];
            num = ch - '0';
            deci = deci * 10 + num;
            i++;
            k++;
            if (s[i] == '.') {
                error('.');
            }
        }
        if (s[i] == '-' && i == (m - 1)) {
            f = -f;
        }
        factor = pow(10, k);
        deci = deci / (double(factor));
        acu = (acu + deci);
    }
    return (acu * f);
}

/***********biblioteca de funciones*************/
double valor(double op1, double op2, char c) {
    double y

;
    switch (c) {
        case '+':
            y = (op1 + op2);
            break;
        case '-':
            y = (op1 - op2);
            break;
        case '*':
            y = (op1 * op2);
            break;
        case '/':
            if (op2 != 0)
                y = (op1 / op2);
            else {
                error(c);
                y = 0;
            }
            break;
        case '^':
            y = pow(op1, op2);
            break;
        //...^  ALT[094]
        default:
            break;
    }
    return y;
}

double valor(double op2, char c) {
    double y = 1;
    switch (c) {
        case '!':
            int k;
            for (k = 1; k <= op2; k++) {
                y *= k;
            }
            break;
        case 'c':
            y = cos(op2 * M_PI / 180);
            break;
        case 't':
            y = tan(op2 * M_PI / 180);
            break;
        case 's':
            y = sin(op2 * M_PI / 180);
            break;
        case 'i':
            if (op2 != 0)
                y = 1 / op2;
            else
                error('/');
            break;
        case 'b':
            y = -op2;
            break;
        case 'r':
            y = op2 * op2;
            break;
        case 'C':
            y = pow(op2, 2) * M_PI;
            break;
        default:
            break;
    }
    return y;
}

/************mensajes de error*************/
void error(char c) {
    gotoxy(18, 6);
    cout << c << "\a Error:";
    switch (c) {
        case '/':
            gotoxy(18, 7);
            cout << "Infinitive Result";
            break;
        case '.':
            gotoxy(18, 7);
            cout << "Invalid Sintaxis";
            break;
        default:
            gotoxy(18, 7);
            cout << "Too Few Arguments";
    }
    getch();
}


