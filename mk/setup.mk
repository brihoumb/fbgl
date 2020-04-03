override CC:=		gcc
override LD:=		$(CC)
override MK:=		mkdir -p
override RM:=		rm -rf

override NAME:=		libbrihoum

override CFLAGS+=	-W -Wall -Wextra
override CPPFLAGS+=	-Iinclude

override OBJ_DIR:=	./obj
override SRC_DIR:=	./src
