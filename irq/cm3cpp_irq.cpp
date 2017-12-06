#include "cm3cpp_irq.h"

#define DEFINE_CALLBACK(cfunc, int_enum)                                            \
    void cfunc(void) {                                                              \
        const uint32_t indx = static_cast<uint32_t>(Interrupt::int_enum);           \
        isr_vector_table[indx]->call();                                             \
    }

namespace cm3cpp {

struct EmptyInterrupt : public IInterruptable {
    void call() {}
    EmptyInterrupt() = default;
    ~EmptyInterrupt() = default;
} _empty_interrupt;

constexpr uint32_t INTERRUPTS_COUNT = NVIC_IRQ_COUNT;
static IInterruptable* isr_vector_table[INTERRUPTS_COUNT];

struct InterruptInitializer {
    InterruptInitializer() {
        for (uint32_t i = 0; i < INTERRUPTS_COUNT; ++i) {
            isr_vector_table[i] = &_empty_interrupt;  // init an irq table with
        }                                             // empty functions for safe
    }
} _init;

void IInterruptable::register_isr(Interrupt interrupt, IInterruptable* interrupt_owner)
{
    const uint32_t indx = static_cast<uint32_t>(interrupt);
    isr_vector_table[indx] = interrupt_owner;
}

BEGIN_DECLS

#ifdef STM32F2
DEFINE_CALLBACK(nvic_wwdg_isr,             ISR_NVIC_WWDG)
DEFINE_CALLBACK(pvd_isr,                   ISR_PVD)
DEFINE_CALLBACK(tamp_stamp_isr,            ISR_TAMP_STAMP)
DEFINE_CALLBACK(rtc_wkup_isr,              ISR_RTC_WKUP)
DEFINE_CALLBACK(flash_isr,                 ISR_FLASH)
DEFINE_CALLBACK(rcc_isr,                   ISR_RCC)
DEFINE_CALLBACK(exti0_isr,                 ISR_EXTI0)
DEFINE_CALLBACK(exti1_isr,                 ISR_EXTI1)
DEFINE_CALLBACK(exti2_isr,                 ISR_EXTI2)
DEFINE_CALLBACK(exti3_isr,                 ISR_EXTI3)
DEFINE_CALLBACK(exti4_isr,                 ISR_EXTI4)
DEFINE_CALLBACK(dma1_stream0_isr,          ISR_DMA1_STREAM0)
DEFINE_CALLBACK(dma1_stream1_isr,          ISR_DMA1_STREAM1)
DEFINE_CALLBACK(dma1_stream2_isr,          ISR_DMA1_STREAM2)
DEFINE_CALLBACK(dma1_stream3_isr,          ISR_DMA1_STREAM3)
DEFINE_CALLBACK(dma1_stream4_isr,          ISR_DMA1_STREAM4)
DEFINE_CALLBACK(dma1_stream5_isr,          ISR_DMA1_STREAM5)
DEFINE_CALLBACK(dma1_stream6_isr,          ISR_DMA1_STREAM6)
DEFINE_CALLBACK(adc_isr,                   ISR_ADC)
DEFINE_CALLBACK(can1_tx_isr,               ISR_CAN1_TX)
DEFINE_CALLBACK(can1_rx0_isr,              ISR_CAN1_RX0)
DEFINE_CALLBACK(can1_rx1_isr,              ISR_CAN1_RX1)
DEFINE_CALLBACK(can1_sce_isr,              ISR_CAN1_SCE)
DEFINE_CALLBACK(exti9_5_isr,               ISR_EXTI9_5)
DEFINE_CALLBACK(tim1_brk_tim9_isr,         ISR_TIM1_BRK_TIM9)
DEFINE_CALLBACK(tim1_up_tim10_isr,         ISR_TIM1_UP_TIM10)
DEFINE_CALLBACK(tim1_trg_com_tim11_isr,    ISR_TIM1_TRG_COM_TIM11)
DEFINE_CALLBACK(tim1_cc_isr,               ISR_TIM1_CC)
DEFINE_CALLBACK(tim2_isr,                  ISR_TIM2)
DEFINE_CALLBACK(tim3_isr,                  ISR_TIM3)
DEFINE_CALLBACK(tim4_isr,                  ISR_TIM4)
DEFINE_CALLBACK(i2c1_ev_isr,               ISR_I2C1_EV)
DEFINE_CALLBACK(i2c1_er_isr,               ISR_I2C1_ER)
DEFINE_CALLBACK(i2c2_ev_isr,               ISR_I2C2_EV)
DEFINE_CALLBACK(i2c2_er_isr,               ISR_I2C2_ER)
DEFINE_CALLBACK(spi1_isr,                  ISR_SPI1)
DEFINE_CALLBACK(spi2_isr,                  ISR_SPI2)
DEFINE_CALLBACK(usart1_isr,                ISR_USART1)
DEFINE_CALLBACK(usart2_isr,                ISR_USART2)
DEFINE_CALLBACK(usart3_isr,                ISR_USART3)
DEFINE_CALLBACK(exti15_10_isr,             ISR_EXTI15_10)
DEFINE_CALLBACK(rtc_alarm_isr,             ISR_RTC_ALARM)
DEFINE_CALLBACK(usb_fs_wkup_isr,           ISR_USB_FS_WKUP)
DEFINE_CALLBACK(tim8_brk_tim12_isr,        ISR_TIM8_BRK_TIM12)
DEFINE_CALLBACK(tim8_up_tim13_isr,         ISR_TIM8_UP_TIM13)
DEFINE_CALLBACK(tim8_trg_com_tim14_isr,    ISR_TIM8_TRG_COM_TIM14)
DEFINE_CALLBACK(tim8_cc_isr,               ISR_TIM8_CC)
DEFINE_CALLBACK(dma1_stream7_isr,          ISR_DMA1_STREAM7)
DEFINE_CALLBACK(fsmc_isr,                  ISR_FSMC)
DEFINE_CALLBACK(sdio_isr,                  ISR_SDIO)
DEFINE_CALLBACK(tim5_isr,                  ISR_TIM5)
DEFINE_CALLBACK(spi3_isr,                  ISR_SPI3)
DEFINE_CALLBACK(uart4_isr,                 ISR_UART4)
DEFINE_CALLBACK(uart5_isr,                 ISR_UART5)
DEFINE_CALLBACK(tim6_dac_isr,              ISR_TIM6_DAC)
DEFINE_CALLBACK(tim7_isr,                  ISR_TIM7)
DEFINE_CALLBACK(dma2_stream0_isr,          ISR_DMA2_STREAM0)
DEFINE_CALLBACK(dma2_stream1_isr,          ISR_DMA2_STREAM1)
DEFINE_CALLBACK(dma2_stream2_isr,          ISR_DMA2_STREAM2)
DEFINE_CALLBACK(dma2_stream3_isr,          ISR_DMA2_STREAM3)
DEFINE_CALLBACK(dma2_stream4_isr,          ISR_DMA2_STREAM4)
DEFINE_CALLBACK(eth_isr,                   ISR_ETH)
DEFINE_CALLBACK(eth_wkup_isr,              ISR_ETH_WKUP)
DEFINE_CALLBACK(can2_tx_isr,               ISR_CAN2_TX)
DEFINE_CALLBACK(can2_rx0_isr,              ISR_CAN2_RX0)
DEFINE_CALLBACK(can2_rx1_isr,              ISR_CAN2_RX1)
DEFINE_CALLBACK(can2_sce_isr,              ISR_CAN2_SCE)
DEFINE_CALLBACK(otg_fs_isr,                ISR_OTG_FS)
DEFINE_CALLBACK(dma2_stream5_isr,          ISR_DMA2_STREAM5)
DEFINE_CALLBACK(dma2_stream6_isr,          ISR_DMA2_STREAM6)
DEFINE_CALLBACK(dma2_stream7_isr,          ISR_DMA2_STREAM7)
DEFINE_CALLBACK(usart6_isr,                ISR_USART6)
DEFINE_CALLBACK(i2c3_ev_isr,               ISR_I2C3_EV)
DEFINE_CALLBACK(i2c3_er_isr,               ISR_I2C3_ER)
DEFINE_CALLBACK(otg_hs_ep1_out_isr,        ISR_OTG_HS_EP1_OUT)
DEFINE_CALLBACK(otg_hs_ep1_in_isr,         ISR_OTG_HS_EP1_IN)
DEFINE_CALLBACK(otg_hs_wkup_isr,           ISR_OTG_HS_WKUP)
DEFINE_CALLBACK(otg_hs_isr,                ISR_OTG_HS)
DEFINE_CALLBACK(dcmi_isr,                  ISR_DCMI)
DEFINE_CALLBACK(cryp_isr,                  ISR_CRYP)
DEFINE_CALLBACK(hash_rng_isr,              ISR_HASH_RNG)
#endif

#ifdef STM32F4
DEFINE_CALLBACK(nvic_wwdg_isr,             ISR_NVIC_WWDG)
DEFINE_CALLBACK(pvd_isr,                   ISR_PVD)
DEFINE_CALLBACK(tamp_stamp_isr,            ISR_TAMP_STAMP)
DEFINE_CALLBACK(rtc_wkup_isr,              ISR_RTC_WKUP)
DEFINE_CALLBACK(flash_isr,                 ISR_FLASH)
DEFINE_CALLBACK(rcc_isr,                   ISR_RCC)
DEFINE_CALLBACK(exti0_isr,                 ISR_EXTI0)
DEFINE_CALLBACK(exti1_isr,                 ISR_EXTI1)
DEFINE_CALLBACK(exti2_isr,                 ISR_EXTI2)
DEFINE_CALLBACK(exti3_isr,                 ISR_EXTI3)
DEFINE_CALLBACK(exti4_isr,                 ISR_EXTI4)
DEFINE_CALLBACK(dma1_stream0_isr,          ISR_DMA1_STREAM0)
DEFINE_CALLBACK(dma1_stream1_isr,          ISR_DMA1_STREAM1)
DEFINE_CALLBACK(dma1_stream2_isr,          ISR_DMA1_STREAM2)
DEFINE_CALLBACK(dma1_stream3_isr,          ISR_DMA1_STREAM3)
DEFINE_CALLBACK(dma1_stream4_isr,          ISR_DMA1_STREAM4)
DEFINE_CALLBACK(dma1_stream5_isr,          ISR_DMA1_STREAM5)
DEFINE_CALLBACK(dma1_stream6_isr,          ISR_DMA1_STREAM6)
DEFINE_CALLBACK(adc_isr,                   ISR_ADC)
DEFINE_CALLBACK(can1_tx_isr,               ISR_CAN1_TX)
DEFINE_CALLBACK(can1_rx0_isr,              ISR_CAN1_RX0)
DEFINE_CALLBACK(can1_rx1_isr,              ISR_CAN1_RX1)
DEFINE_CALLBACK(can1_sce_isr,              ISR_CAN1_SCE)
DEFINE_CALLBACK(exti9_5_isr,               ISR_EXTI9_5)
DEFINE_CALLBACK(tim1_brk_tim9_isr,         ISR_TIM1_BRK_TIM9)
DEFINE_CALLBACK(tim1_up_tim10_isr,         ISR_TIM1_UP_TIM10)
DEFINE_CALLBACK(tim1_trg_com_tim11_isr,    ISR_TIM1_TRG_COM_TIM11)
DEFINE_CALLBACK(tim1_cc_isr,               ISR_TIM1_CC)
DEFINE_CALLBACK(tim2_isr,                  ISR_TIM2)
DEFINE_CALLBACK(tim3_isr,                  ISR_TIM3)
DEFINE_CALLBACK(tim4_isr,                  ISR_TIM4)
DEFINE_CALLBACK(i2c1_ev_isr,               ISR_I2C1_EV)
DEFINE_CALLBACK(i2c1_er_isr,               ISR_I2C1_ER)
DEFINE_CALLBACK(i2c2_ev_isr,               ISR_I2C2_EV)
DEFINE_CALLBACK(i2c2_er_isr,               ISR_I2C2_ER)
DEFINE_CALLBACK(spi1_isr,                  ISR_SPI1)
DEFINE_CALLBACK(spi2_isr,                  ISR_SPI2)
DEFINE_CALLBACK(usart1_isr,                ISR_USART1)
DEFINE_CALLBACK(usart2_isr,                ISR_USART2)
DEFINE_CALLBACK(usart3_isr,                ISR_USART3)
DEFINE_CALLBACK(exti15_10_isr,             ISR_EXTI15_10)
DEFINE_CALLBACK(rtc_alarm_isr,             ISR_RTC_ALARM)
DEFINE_CALLBACK(usb_fs_wkup_isr,           ISR_USB_FS_WKUP)
DEFINE_CALLBACK(tim8_brk_tim12_isr,        ISR_TIM8_BRK_TIM12)
DEFINE_CALLBACK(tim8_up_tim13_isr,         ISR_TIM8_UP_TIM13)
DEFINE_CALLBACK(tim8_trg_com_tim14_isr,    ISR_TIM8_TRG_COM_TIM14)
DEFINE_CALLBACK(tim8_cc_isr,               ISR_TIM8_CC)
DEFINE_CALLBACK(dma1_stream7_isr,          ISR_DMA1_STREAM7)
DEFINE_CALLBACK(fsmc_isr,                  ISR_FSMC)
DEFINE_CALLBACK(sdio_isr,                  ISR_SDIO)
DEFINE_CALLBACK(tim5_isr,                  ISR_TIM5)
DEFINE_CALLBACK(spi3_isr,                  ISR_SPI3)
DEFINE_CALLBACK(uart4_isr,                 ISR_UART4)
DEFINE_CALLBACK(uart5_isr,                 ISR_UART5)
DEFINE_CALLBACK(tim6_dac_isr,              ISR_TIM6_DAC)
DEFINE_CALLBACK(tim7_isr,                  ISR_TIM7)
DEFINE_CALLBACK(dma2_stream0_isr,          ISR_DMA2_STREAM0)
DEFINE_CALLBACK(dma2_stream1_isr,          ISR_DMA2_STREAM1)
DEFINE_CALLBACK(dma2_stream2_isr,          ISR_DMA2_STREAM2)
DEFINE_CALLBACK(dma2_stream3_isr,          ISR_DMA2_STREAM3)
DEFINE_CALLBACK(dma2_stream4_isr,          ISR_DMA2_STREAM4)
DEFINE_CALLBACK(eth_isr,                   ISR_ETH)
DEFINE_CALLBACK(eth_wkup_isr,              ISR_ETH_WKUP)
DEFINE_CALLBACK(can2_tx_isr,               ISR_CAN2_TX)
DEFINE_CALLBACK(can2_rx0_isr,              ISR_CAN2_RX0)
DEFINE_CALLBACK(can2_rx1_isr,              ISR_CAN2_RX1)
DEFINE_CALLBACK(can2_sce_isr,              ISR_CAN2_SCE)
DEFINE_CALLBACK(otg_fs_isr,                ISR_OTG_FS)
DEFINE_CALLBACK(dma2_stream5_isr,          ISR_DMA2_STREAM5)
DEFINE_CALLBACK(dma2_stream6_isr,          ISR_DMA2_STREAM6)
DEFINE_CALLBACK(dma2_stream7_isr,          ISR_DMA2_STREAM7)
DEFINE_CALLBACK(usart6_isr,                ISR_USART6)
DEFINE_CALLBACK(i2c3_ev_isr,               ISR_I2C3_EV)
DEFINE_CALLBACK(i2c3_er_isr,               ISR_I2C3_ER)
DEFINE_CALLBACK(otg_hs_ep1_out_isr,        ISR_OTG_HS_EP1_OUT)
DEFINE_CALLBACK(otg_hs_ep1_in_isr,         ISR_OTG_HS_EP1_IN)
DEFINE_CALLBACK(otg_hs_wkup_isr,           ISR_OTG_HS_WKUP)
DEFINE_CALLBACK(otg_hs_isr,                ISR_OTG_HS)
DEFINE_CALLBACK(dcmi_isr,                  ISR_DCMI)
DEFINE_CALLBACK(cryp_isr,                  ISR_CRYP)
DEFINE_CALLBACK(hash_rng_isr,              ISR_HASH_RNG)
DEFINE_CALLBACK(fpu_isr,                   ISR_FPU)
DEFINE_CALLBACK(uart7_isr,                 ISR_UART7)
DEFINE_CALLBACK(uart8_isr,                 ISR_UART8)
DEFINE_CALLBACK(spi4_isr,                  ISR_SPI4)
DEFINE_CALLBACK(spi5_isr,                  ISR_SPI5)
DEFINE_CALLBACK(spi6_isr,                  ISR_SPI6)
DEFINE_CALLBACK(sai1_isr,                  ISR_SAI1)
DEFINE_CALLBACK(lcd_tft_isr,               ISR_LCD_TFT)
DEFINE_CALLBACK(lcd_tft_err_isr,           ISR_LCD_TFT_ERR)
DEFINE_CALLBACK(dma2d_isr,                 ISR_DMA2D)
#endif

END_DECLS

} /* namespace hw */
