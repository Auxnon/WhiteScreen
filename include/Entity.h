#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        unsigned int getX() { return x; }
        void setX(unsigned int val) { x = val; }
        unsigned int getY() { return y; }
        void setY(unsigned int val) { y = val; }
        unsigned int getZ() { return z; }
        void setZ(unsigned int val) { z = val; }

        unsigned int getW() { return w; }
        void setW(unsigned int val) { w = val; }
        unsigned int getH() { return h; }
        void setH(unsigned int val) { h = val; }

    protected:

    private:
        unsigned int x;
        unsigned int y;
        unsigned int z;

        unsigned int w;
        unsigned int h;
};

#endif // ENTITY_H
