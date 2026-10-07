// Target definition
#define RG_TARGET_NAME              "ESP32-S3-DEVKIT"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI3_HOST
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_DEFAULT

// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable
#define RG_AUDIO_USE_EXT_DAC        1   // 1 = Enable

// Video
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341/ST7789
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_WIDTH             320
#define RG_SCREEN_HEIGHT            240
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_VISIBLE_AREA      {0, 0, 0, 0}
#define RG_SCREEN_SAFE_AREA         {0, 0, 0, 0}

// Инициализация ST7789 с инверсией (0x21)
#define RG_SCREEN_INIT() \
    ILI9341_CMD(0x01);                  /* Software Reset */ \
    rg_task_delay(150); \
    ILI9341_CMD(0x11);                  /* Sleep Out */ \
    rg_task_delay(255); \
    ILI9341_CMD(0x3A, 0x55);            /* Pixel Format (16bit) */ \
    ILI9341_CMD(0x36, 0x60);            /* Memory Access (MX|MV|BGR) */ \
    ILI9341_CMD(0x21);                  /* Display Inversion ON */ \
    ILI9341_CMD(0x13);                  /* Normal Display Mode On */ \
    ILI9341_CMD(0x29);                  /* Display ON */ \
    rg_task_delay(100);

// Input
#define RG_GAMEPAD_ADC_MAP {\
    {RG_KEY_UP,    ADC_UNIT_1, ADC_CHANNEL_5, ADC_ATTEN_DB_11, 3072, 4096},\
    {RG_KEY_RIGHT, ADC_UNIT_1, ADC_CHANNEL_6, ADC_ATTEN_DB_11, 1024, 3071},\
    {RG_KEY_DOWN,  ADC_UNIT_1, ADC_CHANNEL_5, ADC_ATTEN_DB_11, 1024, 3071},\
    {RG_KEY_LEFT,  ADC_UNIT_1, ADC_CHANNEL_6, ADC_ATTEN_DB_11, 3072, 4096},\
}
#define RG_GAMEPAD_GPIO_MAP {\
    {RG_KEY_SELECT, .num = GPIO_NUM_16, .pullup = 1, .level = 0},\
    {RG_KEY_START,  .num = GPIO_NUM_17, .pullup = 1, .level = 0},\
    {RG_KEY_MENU,   .num = GPIO_NUM_18, .pullup = 1, .level = 0},\
    {RG_KEY_OPTION, .num = GPIO_NUM_8,  .pullup = 1, .level = 0},\
    {RG_KEY_A,      .num = GPIO_NUM_15, .pullup = 1, .level = 0},\
    {RG_KEY_B,      .num = GPIO_NUM_5,  .pullup = 1, .level = 0},\
}

// Battery
#define RG_BATTERY_DRIVER           1
#define RG_BATTERY_ADC_UNIT         ADC_UNIT_1
#define RG_BATTERY_ADC_CHANNEL      ADC_CHANNEL_3
#define RG_BATTERY_CALC_PERCENT(raw) (((raw) * 2.f - 3500.f) / (4200.f - 3500.f) * 100.f)
#define RG_BATTERY_CALC_VOLTAGE(raw) ((raw) * 2.f * 0.001f)

// Status LED
#define RG_GPIO_LED                 GPIO_NUM_38

// SPI Display Pins
#define RG_GPIO_LCD_MISO            -1
#define RG_GPIO_LCD_MOSI            GPIO_NUM_11  // SDA (Зеленый)
#define RG_GPIO_LCD_CLK             GPIO_NUM_10  // SCL / SCK (Синий)
#define RG_GPIO_LCD_CS              -1           // Если CS не задействован в GPIO, его заземляем (GND)
#define RG_GPIO_LCD_DC              GPIO_NUM_13  // DC / RS (Желтый)
#define RG_GPIO_LCD_RST             GPIO_NUM_12  // RES / RST (Фиолетовый)
#define RG_GPIO_LCD_BCKL            GPIO_NUM_8   // BLK / LED (Красный)
// SD Card Pins
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_9
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_11
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_13
#define RG_GPIO_SDSPI_CS            GPIO_NUM_10

// External I2S DAC
#define RG_GPIO_SND_I2S_BCK         GPIO_NUM_41
#define RG_GPIO_SND_I2S_WS          GPIO_NUM_42
#define RG_GPIO_SND_I2S_DATA        GPIO_NUM_40
