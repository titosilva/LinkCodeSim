CC=g++
ODIR=obj

_OBJ = main.o Simulador.o CamadaFisica.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $<

linkcodesim: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o