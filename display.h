int open_display(void);
void display_time(int hours, int minutes, int seconds);
void display_colons(uint16_t pixels[8][8]);
void display_hours(uint16_t pixels[8][8], int hours);
void display_minutes(uint16_t pixels[8][8], int minutes);
void display_seconds(uint16_t pixels[8][8], int seconds);
void draw_grid(uint16_t pixels[8][8]);
void close_display(void);
