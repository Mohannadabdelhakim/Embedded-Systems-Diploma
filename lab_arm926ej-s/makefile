#@copyright: Mohannad

CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s 
INCS=-I .
LIBS=
SRC =$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=learn_in_depth

all: $(Project_name).bin
	@echo "_____Build is Done_____"   
	 
%.o : %.c 
	 $(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@    

$(AsOBJ):$(As)
	 $(CC)as.exe $(CFLAGS) $< -o $@     
		
$(Project_name).elf: $(OBJ) $(AsOBJ)
	 $(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@
	 
$(Project_name).bin :$(Project_name).elf
	 $(CC)objcopy.exe -O binary $< $@

clean_all :
	 rm *.o *.bin *.elf
	 
clean : 
	 rm *.bin *.elf
