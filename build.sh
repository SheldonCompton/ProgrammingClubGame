cd /home/sheldon/Work/fasm

./fasm ../Git/ProgrammingClubGame/FDD-BootLoader.asm
./fasm ../Git/ProgrammingClubGame/Kernel0.01.asm
 
cd /home/sheldon/Work/Git/ProgrammingClubGame

dd if=/home/sheldon/Work/Git/ProgrammingClubGame/FDD-BootLoader.bin of=/dev/sdc obs=512 bs=512 count=1
dd if=/home/sheldon/Work/Git/ProgrammingClubGame/Kernel0.01.bin of=/dev/sdc obs=512 seek=1 bs=512 count=1

rm /home/sheldon/Work/Git/ProgrammingClubGame/FDD-BootLoader.bin
rm /home/sheldon/Work/Git/ProgrammingClubGame/Kernel0.01.bin
