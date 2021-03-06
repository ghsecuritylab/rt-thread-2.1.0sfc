#ifndef STM32_SPI_H_INCLUDED
#define STM32_SPI_H_INCLUDED

#include <rtdevice.h>

#include "stm32f4xx.h"
#include "board.h"

//#define RT_USING_SPI_DMA

/* STM32 spi bus driver */
typedef struct drv_hwspi
{
    SPI_HandleTypeDef spiHandle;      
    IRQn_Type irq;
}drv_hwspi_t;

struct stm32_spi_bus
{
    struct rt_spi_bus parent;
    //SPI_TypeDef * SPI;
    SPI_HandleTypeDef spiHandle;
#ifdef RT_USING_SPI_DMA
    DMA_Channel_TypeDef * DMA_Channel_TX;
    DMA_Channel_TypeDef * DMA_Channel_RX;
    uint32_t DMA_Channel_TX_FLAG_TC;
    uint32_t DMA_Channel_TX_FLAG_TE;
    uint32_t DMA_Channel_RX_FLAG_TC;
    uint32_t DMA_Channel_RX_FLAG_TE;
#endif /* RT_USING_SPI_DMA */
};

struct stm32_spi_cs
{
    GPIO_TypeDef * GPIOx;
    uint16_t GPIO_Pin;
};

/* public function list */
rt_err_t stm32_spi_register(SPI_TypeDef * SPI,
                            struct stm32_spi_bus * stm32_spi,
                            const char * spi_bus_name);

#endif // STM32_SPI_H_INCLUDED
