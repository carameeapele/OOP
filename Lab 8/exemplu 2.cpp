#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class domeniu;
class carte;
class biblioteca;

//structura in care se retina data calendaristica
struct calendar
{
    int zi, luna, an;
};

//clasa lista
template <class T>
class lista
{
    T* rad;
    T* point;

public:
    lista();
    ~lista();
    void adaugare(T* q);
    T* cautare(string nume);
    int stergere(string nume);

    //returneaza primul nod
    T* prim()
    {
        point = rad;
        return point;
    }

    //returneaza urmatorul nod
    T* next()
    {
        if (point != NULL)
            point = point->urm;
        return point;
    }

    //returneaza daca un nod este vid sau nu
    int vid()
    {
        if (rad == NULL)
            return 1;
        else
            return 0;
    }
    void elibereaza();
    void afisare();
};

//se initializeaza radacina cu NULL
template <class T>
lista<T>::lista()
{
    rad = NULL;
}

//stergere lista
template <class T>
void lista<T>::elibereaza()
{
    T* p, * q;
    for (p = rad; p != NULL; p = q)
    {
        //se inainteaza in lista si se sterg nodurile
        q = p->urm;
        delete p;
    }

    //radacina devine null
    rad = NULL;
}

//destructorul care sterge lista
template <class T>
lista<T>::~lista()
{
    elibereaza();
}

//adaugare nod in lista
template <class T>
void lista<T>::adaugare(T* q)
{
    T* p;

    //daca lista e nula se adauga primul nod
    if (rad == NULL)
    {
        rad = q;
        return;
    }

    //se adauga ordonat in lista nodurile urmatoare
    for (p = rad; p->urm != NULL; p = p->urm)
        if (p->urm->nume > q->nume)
            break;
    q->urm = p->urm;
    p->urm = q;
}

//stergere element in lista
template <class T>
int lista<T>::stergere(string aux)
{
    T* p, * q;

    //daca nu sunt elemente in lista
    if (rad == NULL)
        return 0;

    //daca se sterge primul nod
    if (rad->nume == aux)
    {
        q = rad;
        rad = rad->urm;
        delete q;
        return 1;
    }

    //daca se sterge nod in interiorul listei
    for (p = rad; p->urm != NULL; p = p->urm)
        if (p->urm->nume == aux)
        {
            q = p->urm;
            p->urm = p->urm->urm;
            delete q;
            return 1;
        }
    return 0;
}

//cautare nod in lista
template <class T>
T* lista<T>::cautare(string aux)
{
    T* p;
    for (p = rad; p != NULL; p = p->urm)
        if (p->nume == aux)
            return p;
    return NULL;
}

//afisare lista
template <class T>
void lista<T>::afisare()
{
    T* p;
    for (p = rad; p != NULL; p = p->urm)
        p->afisare();
}

class carte
{
    string nume, autor, cota, editura;
    int an;
    int nr;
    carte* next;

public:
    calendar impr;
    carte(string, string, string, string, int, int, calendar);
    ~carte();

    void afisare();

    string autorbook()
    {
        return autor;
    }

    string numebook()
    {
        return nume;
    }

    string cotabook()
    {
        return cota;
    }

    string editurabook()
    {
        return editura;
    }

    int anbook()
    {
        return an;
    }

    int nrbook()
    {
        return nr;
    }

    friend class lista<carte>;
};

carte::carte(string n, string t, string c, string e, int a, int N, calendar i)
{
    nume = n;
    autor = t;
    cota = c;
    editura = e;
    an = a;
    nr = N;
    impr = i;
    urm = NULL;
}

carte::~carte()
{
    delete& nume;
    delete& autor;
    delete& cota;
    delete& editura;

    impr.zi = impr.luna = impr.an = 0;
    an = nr = 0;
}

void carte::afisare()
{
    cout << endl;
    cout << "Autorul: " << autor << endl;
    cout << "Titlu: " << nume << endl;
    cout << "Cota: " << cota << endl;
    cout << "Editura: " << editura << endl;
    cout << "Anul aparitiei: " << an << endl;
    cout << "Numar editie: " << nr << endl;
    cout << "Imprumutata(0/calendar): ";

    if (impr.zi == 0)
        cout << impr.zi << endl;
    else
        cout << impr.zi << "/" << impr.luna << "/" << impr.an << endl;
}

class domeniu
{
protected:
    string nume;
    lista<carte> book;
    domeniu* urm;
public:
    domeniu(string);
    ~domeniu();

    void adaugarebook(carte* q)
    {
        book.adaugare(q);
    }

    carte* cautarebook(string aux)
    {
        return book.cautare(aux);
    }

    int stergerebook(string aux)
    {
        return book.stergere(aux);
    }

    string numedom()
    {
        return nume;
    }

    carte* primbook()
    {
        return book.prim();
    }

    carte* nextbook()
    {
        return book.next();
    }

    virtual void afisare();

    friend class lista<domeniu>;
};

domeniu::domeniu(string n)
{
    nume = n;
    urm = NULL;
}
domeniu::~domeniu()
{
    delete& nume;
}
void domeniu::afisare()
{
    cout << endl;
    cout << "Domeniu: " << nume << endl;
    book.afisare();
}

class biblioteca
{
    lista<domeniu> dom;

public:
    void adaugaredom(domeniu* aux)
    {
        dom.adaugare(aux);
    }
    domeniu* cautaredom(string aux)
    {
        return dom.cautare(aux);
    }
    int stergeredom(string aux)
    {
        return dom.stergere(aux);
    }
    void elibereaza()
    {
        dom.elibereaza();
    }
    void afisare()
    {
        dom.afisare();
    }
    domeniu* primdom()
    {
        return dom.prim();
    }
    domeniu* nextdom()
    {
        return dom.next();
    }
};

void meniu()
{
    cout << endl;
    cout << "1.Incarcare biblioteca dintr-un fisier" << endl;
    cout << "2.Creare domeniu nou" << endl;
    cout << "3.Adaugare carte la un anumit domeniu" << endl;
    cout << "4.Cautare carte in biblioteca" << endl;
    cout << "5.Stergere carte din biblioteca" << endl;
    cout << "6.Salvare in fisier a bibliotecii" << endl;
    cout << "7.Iesire" << endl;
    cout << "0.Afisare" << endl;
    cout << "Optiunea: " << endl;
}

carte* read_book()
{
    carte* c;
    string nume, autor, cota, editura;
    int an;
    int nr;
    calendar impr;
    cout << "\nAutor: ";
    cin >> autor;
    cout << "\nTitlu: ";
    cin >> nume;
    cout << "\nCota: ";
    cin >> cota;
    cout << "\nEditura: ";
    cin >> editura;
    cout << "\nAnul aparitiei: ";
    cin >> an;
    cout << "\nNumar editie: ";
    cin >> nr;
    cout << "\nImprumutata(0/calendar-zi luna an): ";
    cin >> impr.zi;
    if (impr.zi == 0)
        impr.luna = impr.an = 0;
    else
    {
        cin >> impr.luna;
        cin >> impr.an;
    }
    c = new carte(nume, autor, cota, editura, an, nr, impr);
    return c;
}

//citire date din fisier
void cit_fisier(biblioteca* b)
{
    domeniu* d;
    carte* c;
    ifstream f;
    string aux, nume, autor, editura, cota;
    calendar impr;
    int an, nr;
    f.open("carti.txt");
    while (!f.eof())
    {
        aux = f.get();
        if (aux == "d")
        {
            f.ignore(1);
            getline(f, nume);
            d = new domeniu(nume);
            b->adaugaredom(d);
        }
        if (aux == "c")
        {
            f.ignore(1);
            f >> autor;
            f >> nume;
            f >> cota;
            f >> editura;
            f >> an;
            f >> nr;
            f >> impr.zi;
            if (impr.zi == 0)
                impr.luna = impr.an = 0;
            else
            {
                f >> impr.luna;
                f >> impr.an;
            }
            c = new carte(nume, autor, cota, editura, an, nr, impr);
            if (d != NULL)
                d->adaugarebook(c);
            f.ignore(1000, '\n');
        }
    }
    f.close();
}

void save_fisier(biblioteca* b)
{
    domeniu* d;
    carte* c;
    ofstream f;
    f.open("carti.txt");
    d = b->primdom();
    while (d != NULL)
    {
        f << "d ";
        f << d->numedom() << "\n";
        c = d->primbook();
        while (c != NULL)
        {
            f << "c " << c->autorbook() << " " << c->numebook() << " " << c->cotabook() << " ";
            f << c->editurabook() << " " << c->anbook() << " " << c->nrbook() << " ";
            if (c->impr.zi == 0)
                f << c->impr.zi << "\n";
            else
                f << c->impr.zi << " " << c->impr.luna << " " << c->impr.an << "\n";
            c = d->nextbook();
        }
        d = b->nextdom();
    }
}

int main()
{
    int opt, x;
    carte* c = NULL;
    domeniu* d = NULL;
    biblioteca b;
    string aux;
    do
    {
        meniu();
        cin >> opt;
        switch (opt)
        {
        case 1:
            cit_fisier(&b);
            b.afisare();
            _getch();
            break;
        case 2:
            cout << "\n Introduceti numele domeniului: ";
            cin >> aux;
            d = b.cautaredom(aux);
            if (d == NULL)
            {
                d = new domeniu(aux);
                b.adaugaredom(d);
                cout << "\n Domeniul a fost adaugat";
                _getch();
            }
            else
            {
                cout << "\n Domeniul exista deja !";
                _getch();
            }
            d = NULL;
            b.afisare();
            _getch();
            break;
        case 3:
            cout << "\n Introduceti numele domeniului:";
            cin >> aux;
            d = b.cautaredom(aux);
            if (d == NULL)
            {
                cout << "\n Domeniul introdus nu exista!";
                _getch();
            }
            else
            {
                c = read_book();
                d->adaugarebook(c);
            }
            d = NULL;
            c = NULL;
            b.afisare();
            _getch();
            break;
        case 4:
            cout << "\n Introduceti numele domeniului: ";
            cin >> aux;
            d = b.cautaredom(aux);
            if (d == NULL)
            {
                cout << "\n Domeniul introdus nu exista!";
                _getch();
            }
            else
            {
                cout << "\n Introduceti titlul cartii: ";
                cin >> aux;
                c = d->cautarebook(aux);
                if (c != NULL)
                {
                    cout << "\n Cartea se afla in biblioteca";
                    _getch();
                }
                else
                {
                    cout << "\n Cartea nu se afla in biblioteca";
                    _getch();
                }
            }
            break;
        case 5:
            cout << "\n Introduceti numele domeniului: ";
            cin >> aux;
            d = b.cautaredom(aux);
            if (d == NULL)
            {
                cout << "\n Domeniul introdus nu exista";
                _getch();
            }
            else
            {
                cout << "\n Introduceti titlul cartii: ";
                cin >> aux;
                x = d->stergerebook(aux);
            }
            if (x == 1)
            {
                cout << "\n Cartea a fost stearsa";
                _getch();
            }
            else
            {
                cout << "\n Cartea nu se afla in biblioteca";
                _getch();
            }
            break;
        case 6:
            save_fisier(&b);
            cout << "\n Datele au fost salvate in fisier";
            _getch();
            break;
        case 7:
            break;
        case 0:
            b.afisare();
            _getch();
            break;
        default:
            cout << "\n Optiune gresita";
            break;
        }
    } while (opt != 7);
    return 0;
}