#include <iostream>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>

//Valores de la ventana segun tamaño width x height
#define ScreenWidth 1200
#define ScreenHeight 1000

//Variables para crear las animaciones de los soldados
bool noMove = true;
bool canMove = true;
int frame = 0;

using namespace std;

//Metodo para centrar el soldado en el centro del cuadro
int center (int pos)
{
    if (pos > 0 && pos <= 100){ return 18;}
    else if (pos > 100 && pos <= 200){ return 118;}
    else if (pos > 200 && pos <= 300){ return 218;}
    else if (pos > 300 && pos <= 400){ return 318;}
    else if (pos > 400 && pos <= 500){ return 418;}
    else if (pos > 500 && pos <= 600){ return 518;}
    else if (pos > 600 && pos <= 700){ return 618;}
    else if (pos > 700 && pos <= 800){ return 718;}
    else if (pos > 800 && pos <= 900){ return 818;}
    else if (pos > 900 && pos <= 1000){ return 918;}
    else if (pos > 1000 && pos <= 1100){ return 1018;}
    else if (pos > 1100 && pos <= 1200){ return 1118;}
}

//Metodo que crea el escenario a partir de una matriz 10x12
//0 es terreno
//1 obstaculos
void drawMap(ALLEGRO_BITMAP *Map,ALLEGRO_BITMAP *obstacule,int matriz[10][12])
{
    int posX = 1;
    int posY = 1;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 12; j++){
            if (matriz [i][j] = 0)
            {
                al_draw_bitmap_region(Map, 0, 0, 98, 98, posX, posY, 0);
                posX += 100;
            }
            else if (matriz [i][j] = 1)
            {
                al_draw_bitmap_region(obstacule, 0, 0, 98, 98, posX, posY, 0);
                posX += 100;
            }
        }
        if (posX == 1201)
        {
            posX = 1;
            posY += 100;
        }

    }

}
//Metodo para las animaciones de los personajes, se pone el bitmap del personaje
//la posicion X y Y a la que se quieren llegar
//y el valor del pixel donde está la imagen.png en pixeles
void moveFrame (ALLEGRO_BITMAP *soldier, int posX, int posY, int frameSprite){

    if (frame == 0){

        al_draw_bitmap_region(soldier, 0, 0, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));

    }

    else if(frame == 1) {

        al_draw_bitmap_region(soldier, 64, frameSprite, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        frame += 1;

    }else if (frame == 2){

        al_draw_bitmap_region(soldier, 128, frameSprite, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        frame += 1;

    }else if (frame == 3) {

        al_draw_bitmap_region(soldier, 192, frameSprite, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        frame += 1;

    }else if (frame == 4){

        al_draw_bitmap_region(soldier, 256, frameSprite, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        frame += 1;

    }else if (frame == 5){

        al_draw_bitmap_region(soldier, 320, frameSprite, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        frame += 1;

    }else{

        al_draw_bitmap_region(soldier, 384, frameSprite, 64, 64, posX, posY, 0);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        frame += 1;

    }

}

//Metodo que utiliza el metodo drawFrame para plasmar las imagenes en el proyecto
void draw (ALLEGRO_BITMAP *soldier, int posX, int posY, int direction)
{

    if (frame == 7){

        frame = 1;

    }
    if (direction == 0)
    {
        moveFrame(soldier, posX, posY, 0);
    }

    else if (direction == 1){

        moveFrame (soldier, posX, posY, 576);

    } else if (direction == 2){

       moveFrame (soldier, posX, posY, 704);


    } else if (direction == 3){

        moveFrame (soldier, posX, posY, 512);

    } else if (direction == 4){

        moveFrame (soldier, posX, posY, 640);

    }
}

int main() {

    //se crea el display o ventana
    ALLEGRO_DISPLAY *display;

    //matriz paara el mapa 10 x 12
    int matriz[10][12];

    //Matriz 10x12 prueba
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {

            matriz[i][j] = 0;

        }
    }

    //Direcciones en las que se va a mover el personaje una vez que se clickee
    //La primera palabra representa a la derecha o izquierda
    //la ultima letra arriba o abajo
    enum direction {
        LEFTD, LEFTU, RIGHTD, RIGHTU, NONE
    };

    const float fps = 15.0;
    const int interval = 5;

    //se inicia allegro
    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    //se le da las dimensiones a la ventana
    display = al_create_display(ScreenWidth, ScreenHeight);

    //Se cerifica si existe algun error al crear la ventana
    if (!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
    //Posicion el la que saldrá la ventana en la pantalla
    al_set_window_position(display, 100, 100);

    //Variables que se utilizaran para crear salidas y restricciones del juego
    bool done = false, active = false;
    int x, y, goX, goY, moveSpeed = 10;
    int dir = NONE;

    //posicion en X y Y en las que inician los personajes
    int posX = 18, posY = 18;

    al_install_mouse();
    al_init_image_addon();

    //Se cargan las imagenes
    ALLEGRO_BITMAP *soldier = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Lasswell.png");
    ALLEGRO_BITMAP *enemy = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Raegen.png");
    ALLEGRO_BITMAP *map = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Grass.png");
    ALLEGRO_BITMAP *obstacule = al_load_bitmap("C:/Users/Ba/CLionProjects/LeagueOfGems/Tree.png");

    //Se crean los timers y cola de eventos
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / fps);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    //se mete all dentro de la cola de eventos
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_mouse_event_source());

    //Se inicial el timer
    al_start_timer(timer);

    //Bucle del juego
    while (!done)
    {
        //Variable eventos sobre la que funciona el juego
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);

        //se dibuja el mapa
        drawMap(obstacule, map, matriz);

        //Verifica si se presiona la x de la ventana para cerrar el juego
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        //Se verifica si el personaje no se está moviendo para poner su imagen inicial
        if (noMove == true)
        {
            draw(soldier, posX, posY, 0);
        }

        //da los valores en X y Y de donde esta el mouse en la ventana
        if (events.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            goX = events.mouse.x;
            goY = events.mouse.y;
        }

        //Evento que verifica si se presiono un boton del mouse
        if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            //verifica que el no se esté moviendo hacia una casilla antes de darle otra ubicacion
            if (canMove == true) {
                //Verifica si el click que se presionó es el derecho
                if (events.mouse.button & 2) {

                    //centra los valores del click
                    x = center(goX);
                    y = center(goY);

                    active = true;
                    noMove = false;
                    canMove = false;
                    frame = 1;

                    //busca en que direccion debe moverse el soldado
                    if (posX <= x && posY <= y) {
                        dir = RIGHTD;
                        cout << "RD" << endl;
                    } else if (posX <= x && posY >= y) {
                        dir = RIGHTU;
                        cout << "RU" << endl;
                    } else if (posX >= x && posY <= y) {
                        dir = LEFTD;
                        cout << "LD" << endl;
                    } else {
                        dir = LEFTU;
                        cout << "LU" << endl;
                    }


                }
            }
        }
        //Verifica si se active es verdadero (se vuelve verdadero al momento de dar click derecho)
        if (active == true) {
            if (events.type == ALLEGRO_EVENT_TIMER) {

                if (dir == RIGHTD) {
                    if  (posX != x) {
                        posX += moveSpeed;
                        draw(soldier, posX, posY, 2);
                    }

                    else if  (posY != y) {
                        posY += moveSpeed;
                        draw(soldier, posX, posY, 3);
                    }

                }
                if (dir == RIGHTU) {
                    if (posX != x) {
                        posX += moveSpeed;
                        draw(soldier, posX, posY, 2);
                    }

                    else if  (posY != y) {
                        posY -= moveSpeed;
                        draw(soldier, posX, posY, 1);
                    }

                }
                if (dir == LEFTD) {
                    if (posX != x) {
                        posX -= moveSpeed;
                        draw(soldier, posX, posY, 4);
                    }

                    else if  (posY != y) {
                        posY += moveSpeed;
                        draw(soldier, posX, posY, 3);;
                    }

                }
                if (dir == LEFTU) {
                    if (posX != x) {
                        posX -= moveSpeed;
                        draw(soldier, posX, posY, 4);
                    }

                    else if (posY != y) {
                        posY -= moveSpeed;
                        draw(soldier, posX, posY, 1);;
                    }

                }
                //Si el valor de la posicion del soldado llega a la posicion donde
                //se clickeo todo vuelve a ser estatico
                //exceptuando el valor de la posicion del soldado
                if (posX == x && posY == y)
                {
                    dir == NONE;
                    active = false;
                    frame = 0;
                    noMove = true;
                    moveSpeed = 10;
                    canMove = true;
                }



            }
        }



    }

 // destruye la ventana y se sale
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_bitmap(soldier);
    al_destroy_event_queue(event_queue);

    return 0;
}

