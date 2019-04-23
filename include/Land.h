#ifndef LAND_H
#define LAND_H


class Land
{
    public:
        Land();
        virtual ~Land();

        unsigned int Getx() { return x; }
        void Setx(unsigned int val) { x = val; }
        unsigned int** getCells(){ return cells;}

    protected:

    private:
        unsigned int x;
        unsigned int cells[16][16];
};

#endif // LAND_H
