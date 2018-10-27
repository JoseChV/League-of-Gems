//
// Created by jose on 18/10/18.
//

#ifndef LOG_ENEMY_H
#define LOG_ENEMY_H


class Enemy {
private:
    int genes[4]; //0: ataque, 1: vida, 2: velocidad de ataque, 3: resistencia al daño.
    int mutationGenes[3];


public:

    int attack, hp;
    double attSpeed, dmgReduction;

    Enemy(int genes[4], int mutationGenes[3]){
        for(int i=0;i<4;i++) {
            this->genes[i] = genes[i];
            if (i < 3) {
                this->mutationGenes[i] = mutationGenes[i];
            }
        }

        this->attack = 80 + genes[0] * 12;
        this->hp = 500 + genes[0] * 115;
        this->attSpeed = 0.650 + genes[2] * 0.2;
        this->dmgReduction = 20 + genes[3] * 8.5;

    }

    const int *getMutationGenes() const;
    const int *getGenes() const;

};


#endif //LOG_ENEMY_H
