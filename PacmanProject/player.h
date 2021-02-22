#ifndef PLAYER_H
#define PLAYER_H


class Player{
    private:
        int xPosition;
        int yPosition;
        bool isAlive;
        char representation;
    public:
        Player(int _xPos, int _yPos);
        ~Player();
        int getXPosition() const;
        int getYPosition() const;
        char getRepresentation() const;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

};

#endif // PLAYER_H