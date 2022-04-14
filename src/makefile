CC=g++
ODIR=obj
DOLLAR := $

_OBJ = main.o Simulador.o Maquina/Maquina.o Utilitario.o CamadaAplicacao/Aplicacao.o CamadaAplicacao/CamadaAplicacao.o CamadaEnlace/Enquadramento.o CamadaEnlace/CamadaEnlace.o CamadaFisica/Codificacoes.o CamadaFisica/CamadaFisica.o UI/UIBasics.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
SUBDIRS = Maquina CamadaAplicacao CamadaEnlace CamadaFisica UI

$(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) -c -o $@ $<

linkcodesim: $(OBJ)
	$(CC) -o $@ $^

$(ODIR):
	mkdir $(ODIR) && for d in $(SUBDIRS); do mkdir "$(ODIR)/$(DOLLAR)d"; done

.PHONY: clean

clean:
	rm -rf $(ODIR)/ linkcodesim