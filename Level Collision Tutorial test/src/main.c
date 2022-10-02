#include <genesis.h>
#include <resources.h>

#define MAP1_WIDTH 768
#define MAP1_HEIGHT 480

u8 SOLID_TILE = 1;
u8 PLATFORM_TILE = 2;
u8 STAIRS_TILE = 3;

u8 length_array = 48; //how many tiles wide is the level

u16 how_close_to_left_before_camera_moves = 100;
u16 how_close_to_right_before_camera_moves = 224;

const u8 level[1440] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,

    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,

    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,

    1, 1, 1, 1, 1, 1, 1, 1, 0, 0,      0, 0, 0, 0, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 0, 0, 0, 0, 0,      1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0,      0, 0, 0, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 0, 0, 0, 0,      0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0,      0, 0, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 0, 0, 0,      0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 1, 1, 0, 0, 0, 0, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 0, 0, 0, 0, 1, 1, 1, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      1, 1, 0, 0, 0, 0, 0, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 0, 0, 0, 0, 0, 1, 1, 1, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 1,      1, 0, 0, 0, 0, 0, 0, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 0, 0, 0, 0, 0, 0, 1, 1, 0,      0, 0, 0, 0, 0, 1, 1, 1,

    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 0, 0, 2, 2, 2, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      2, 2, 2, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,

    1, 1, 0, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 0, 0, 0, 1, 1, 1, 0,      0, 1, 1, 1, 1, 0, 0, 0, 1, 1,      1, 1, 0, 0, 1, 1, 1, 1, 1, 1,      1, 1, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,      1, 1, 1, 1, 1, 1, 1, 1
    
};

u16 bgBaseTileIndex[2];
Map* bga;
Map* bgb;

Sprite* alucard;
fix32 alucard_x = FIX32(100);
fix32 alucard_y = FIX32(50);
fix32 x_vel = FIX32(1.5);
fix32 y_vel = FIX32(0);
fix32 gravity = FIX32(0.3);
bool move_left = FALSE;
bool move_right = FALSE;

bool hit_head = FALSE;

int jump_counter = 0;
bool jumping = FALSE;

int camPosX;
int camPosY;

static void controls();
static void levelCollision();
static void setSpritePosition(Sprite* sprite, int x, int y);
static void updateCameraPosition();
static void setCameraPosition(int x, int y);


int main()
{
    SPR_init(0, 0, 0);
    u16 ind = TILE_USERINDEX;

    PAL_setPalette(PAL0, bgb_map.palette->data, DMA);
    PAL_setPalette(PAL1, bga_map.palette->data, DMA);
    PAL_setPalette(PAL2, alucard_sprite.palette->data, DMA);

    bgBaseTileIndex[0] = ind;
    VDP_loadTileSet(&bga_tileset, ind, DMA);
    bga = MAP_create(&bga_map, BG_A, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, bgBaseTileIndex[0])); 
    ind += bga_tileset.numTile;
    bgBaseTileIndex[1] = ind;
    VDP_loadTileSet(&bgb_tileset, ind, DMA);
    bgb = MAP_create(&bgb_map, BG_B, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, bgBaseTileIndex[1])); 
    ind += bgb_tileset.numTile;

    DMA_setBufferSize(9000);
    MAP_scrollTo(bgb, 0, 0);
    MAP_scrollTo(bga, 0, 0);
    SYS_doVBlankProcess();
    DMA_setBufferSizeToDefault();

    alucard = SPR_addSprite(&alucard_sprite, fix32ToInt(alucard_x), fix32ToInt(alucard_y), TILE_ATTR(PAL2, FALSE, FALSE, FALSE));


    
    
    while(1)
    {
        // if (hit_head) {
        //     if (y_vel < FIX32(0.2)) y_vel = FIX32(0.2);
        // } 
        controls();
        levelCollision();
        SPR_update();
        SYS_doVBlankProcess();

    }
    return (0);
}


 static void controls() {
    u16 value = JOY_readJoypad(JOY_1);

    if (value & BUTTON_LEFT) {
        move_left = TRUE;
    }
    else if ( !(value & BUTTON_LEFT)) {
        move_left = FALSE;
    }

    if (value & BUTTON_RIGHT) {
        move_right = TRUE;
    }
    else if ( !(value & BUTTON_RIGHT)) {
        move_right = FALSE;
    } 

    if (value & BUTTON_UP) {
        alucard_y = fix32Sub(alucard_y, x_vel);
    }
    else if (value & BUTTON_DOWN) {
        alucard_y = fix32Add(alucard_y, x_vel);
    }
    

    if (value & BUTTON_A) {
        alucard_x = fix32Sub(alucard_x, x_vel);
    }
    if ((value & BUTTON_B) && !hit_head) {
        if (jump_counter == 0) jumping = TRUE;
        if (jump_counter < 4) y_vel = fix32Sub(y_vel, FIX32(2));
        jump_counter +=1;
    }
    // else if (!(value & BUTTON_B)) {
    //     jump_counter = 0;
    // }
    if (value & BUTTON_C) {
        alucard_x = fix32Add(alucard_x, x_vel);
    }
}


static void levelCollision() {

    int alucard_x_int;
    int alucard_y_int;
    int future_x_divide;
    int future_y_divide;

    int future_tile_x_t;
    int future_tile_x_m;
    int future_tile_x_m2;
    int future_tile_x_b;

    alucard_y_int = fix32ToInt(alucard_y);
    alucard_x_int = fix32ToInt(alucard_x);
    future_y_divide = alucard_y_int >> 4;

    if (move_left){
        
        
        future_x_divide = alucard_x_int >> 4;
        

        future_tile_x_t = level[future_y_divide * length_array + future_x_divide];
        future_tile_x_m = level[ (future_y_divide + 1) * length_array + future_x_divide];
        future_tile_x_m2 = level[ (future_y_divide + 2) * length_array + future_x_divide];
        future_tile_x_b = level[ (future_y_divide + 3) * length_array + future_x_divide];
        // alucard_x = fix32Sub(alucard_x, x_vel);
        //	futureTileTopLeft = level[futureYDivideUpper * length_array + futureXDivide];

        if (    future_tile_x_t != SOLID_TILE && 
                future_tile_x_m != SOLID_TILE && 
                future_tile_x_m2 != SOLID_TILE &&
                future_tile_x_b != SOLID_TILE) {

                alucard_x = fix32Sub(alucard_x, x_vel);
        }
    

    }
    else if (move_right) {
        future_x_divide = (alucard_x_int + 24) >> 4;
     

        future_tile_x_t = level[future_y_divide * length_array + future_x_divide];
        future_tile_x_m = level[ (future_y_divide + 1) * length_array + future_x_divide];
        future_tile_x_m2 = level[ (future_y_divide + 2) * length_array + future_x_divide];
        future_tile_x_b = level[ (future_y_divide + 3) * length_array + future_x_divide];
        // alucard_x = fix32Sub(alucard_x, x_vel);
        //	futureTileTopLeft = level[futureYDivideUpper * length_array + futureXDivide];

        if (    future_tile_x_t != SOLID_TILE && 
                future_tile_x_m != SOLID_TILE && 
                future_tile_x_m2 != SOLID_TILE &&
                future_tile_x_b != SOLID_TILE) {

                alucard_x = fix32Add(alucard_x, x_vel);
        }
    
        // alucard_x = fix32Add(alucard_x, x_vel);
    }   

    fix32 vel_with_gravity = FIX32(0);
    fix32 future_y = FIX32(0); 
    int future_bottom_tile;
    int floor_y;


    // vel_with_gravity = fix32Add(y_vel, gravity);
    y_vel = fix32Add(y_vel, gravity);
    future_y = fix32Add(y_vel, alucard_y);
    alucard_y_int = fix32ToInt(future_y);
    future_y_divide = (alucard_y_int + 48) >> 4;
    future_x_divide = (alucard_x_int + 12) >> 4;
    future_bottom_tile = level[future_y_divide * length_array + future_x_divide];

    alucard_y = future_y;

    if (future_bottom_tile == SOLID_TILE) {
        y_vel = FIX32(0);
        floor_y = (future_y_divide << 4) - 48;
        alucard_y = intToFix32(floor_y);
        alucard_y = fix32Sub(alucard_y, 0.1);
        jumping = FALSE;
        jump_counter = 0;

    }

    future_y_divide = alucard_y_int >> 4;
    future_bottom_tile = level[future_y_divide * length_array + future_x_divide];

    fix32 top_tile_y;

    if (future_bottom_tile == SOLID_TILE) {
        // y_vel = fix32Sub(FIX32(0), y_vel);
        
        floor_y = (future_y_divide << 4);
        top_tile_y = intToFix32(floor_y);
        if (alucard_y < top_tile_y) alucard_y = top_tile_y;
        hit_head = TRUE;
        if (y_vel < 0) y_vel = FIX32(0.8);

        //alucard_y = intToFix32(floor_y);
        // alucard_y = fix32Sub(alucard_y, 0.1);
    }
    else hit_head = FALSE;


    // else {
    //     //alucard_y = (future_bottom_tile << 4) - 48;
        

    // } 
    


    updateCameraPosition();
    setSpritePosition(alucard, fix32ToInt(alucard_x) - camPosX, fix32ToInt(alucard_y) - camPosY);
    
}

static void setSpritePosition(Sprite* sprite, int x, int y)
{
    // Clip out of screen sprites
    if ((x < -120) || (x > 320) || (y < -100) || (y > 240)) SPR_setVisibility(sprite, HIDDEN);
    else
    {
        SPR_setVisibility(sprite, VISIBLE);
        SPR_setPosition(sprite, x, y);
    }
}


static void updateCameraPosition()
{
    // Get player position (pixel)
    int px = fix32ToInt(alucard_x);
    int py = fix32ToInt(alucard_y);

    // Current sprite position on screen
    int px_scr = px - camPosX;
    int py_scr = py - camPosY;

    //s16 npx_cam, npy_cam;
	int npx_cam;
	int npy_cam;
    
    // Adjust new camera position 
    if (px_scr > how_close_to_right_before_camera_moves) npx_cam = px - how_close_to_right_before_camera_moves; //HOW CLOSE TO RIGHT BEFORE CAMERA MOVES
    else if (px_scr < how_close_to_left_before_camera_moves) npx_cam = px - how_close_to_left_before_camera_moves; //HOW CLOSE TO LEFT BEFORE CAMERA MOVES
    else npx_cam = camPosX;
    if (py_scr > 100) npy_cam = py - 100;
    else if (py_scr < 40) npy_cam = py - 40;
    else npy_cam = camPosY;
    
    // Clip camera position - STOPS THE CAMERA FROM EXCEEDING THE BOUNDARIES OF THE LEVEL 
    if (npx_cam < 0) npx_cam = 0;
    else if (npx_cam > (MAP1_WIDTH - 320)) npx_cam = (MAP1_WIDTH - 320);
    if (npy_cam < 0) npy_cam = 0;
    else if (npy_cam > (MAP1_HEIGHT - 224)) npy_cam = (MAP1_HEIGHT - 224);

    // Set new camera position
    setCameraPosition(npx_cam, npy_cam);
}

static void setCameraPosition(int x, int y)
{
    if ((x != camPosX) || (y != camPosY))
    {
        camPosX = x;
        camPosY = y;

        MAP_scrollTo(bga, x, y); 
        MAP_scrollTo(bgb, x, y);    

    }
}