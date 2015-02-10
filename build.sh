cd /home/sheldon/Desktop/fasm

./fasm ../Git/ProgrammingClubGame/BootLoader0.03.asm
./fasm ../Git/ProgrammingClubGame/Kernel0.01.asm
 
cd /home/sheldon/Desktop/Git/ProgrammingClubGame

dd if=/home/sheldon/Desktop/Git/ProgrammingClubGame/BootLoader0.03.bin of=/dev/sdc obs=512 bs=512 count=1
dd if=/home/sheldon/Desktop/Git/ProgrammingClubGame/Kernel0.01.bin of=/dev/sdc obs=512 bs=512 count=1

rm /home/sheldon/Desktop/Git/ProgrammingClubGame/BootLoader0.03.bin
rm /home/sheldon/Desktop/Git/ProgrammingClubGame/Kernel0.01.bin
