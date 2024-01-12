#@copyright: Mohannad

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -g -gdwarf-2
INCS=-I .
LIBS=
SRC =$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=learn_in_depth_cortex_M4

all: $(Project_name).bin
	@echo "_____Build is Done_____"   
	 
%.o : %.c 
	 $(CC)gcc.exe -c $(INCS) $(CFLAGS) -mthumb $< -o $@    

$(AsOBJ):$(As)
	 $(CC)as.exe $(CFLAGS) $< -o $@     
		
$(Project_name).elf: $(OBJ) $(AsOBJ)
	 $(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	 cp $(Project_name).elf $(Project_name).axf

	 
$(Project_name).bin :$(Project_name).elf
	 $(CC)objcopy.exe -O binary $< $@

clean_all :
	 rm *.o *.bin *.elf
	 
clean : 
	 rm *.bin *.elf
