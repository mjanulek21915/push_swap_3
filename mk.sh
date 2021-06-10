#-fsanitize=address -g \
reset
tgt_main="main"
gcc src/main/$tgt_main.c src/lib/*.c debug/*.c src/init/*.c \
-I inc \