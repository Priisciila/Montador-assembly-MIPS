#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 400

// Função para converter um número decimal para uma string binária 
char *decimal_para_binario(int n, int comprimento) {
    char *p = (char *)malloc(comprimento + 1);
    if (p == NULL) exit(EXIT_FAILURE);

    for (int c = comprimento - 1; c >= 0; c--) {
        p[c] = (n >> (comprimento - 1 - c)) & 1 ? '1' : '0';
    }
    p[comprimento] = '\0';
    return p;
}

// Função para obter o código binário de uma instrução MIPS
char *obterCodigoBinario(char *comando, char *res1, char *res2, char *res3) {
    int opcode, rs, rt, rd, funct, imediato, endereco_j;
    char *binario = (char *)malloc(33); // 32 bits + 1 para o terminador nulo

    if (binario == NULL) exit(EXIT_FAILURE);

    if (strcmp(comando, "add") == 0) {
        opcode = 0x00; funct = 0x20; rs = atoi(res2); rt = atoi(res3); rd = atoi(res1);
        sprintf(binario, "%s%s%s%s00000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(rd, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "sub") == 0) {
        opcode = 0x00; funct = 0x22; rs = atoi(res2); rt = atoi(res3); rd = atoi(res1);
        sprintf(binario, "%s%s%s%s00000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(rd, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "and") == 0) {
        opcode = 0x00; funct = 0x24; rs = atoi(res2); rt = atoi(res3); rd = atoi(res1);
        sprintf(binario, "%s%s%s%s00000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(rd, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "or") == 0) {
        opcode = 0x00; funct = 0x25; rs = atoi(res2); rt = atoi(res3); rd = atoi(res1);
        sprintf(binario, "%s%s%s%s00000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(rd, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "xor") == 0) {
        opcode = 0x00; funct = 0x26; rs = atoi(res2); rt = atoi(res3); rd = atoi(res1);
        sprintf(binario, "%s%s%s%s00000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(rd, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "slt") == 0) {
        opcode = 0x00; funct = 0x2a; rs = atoi(res2); rt = atoi(res3); rd = atoi(res1);
        sprintf(binario, "%s%s%s%s00000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(rd, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "jr") == 0) {
        opcode = 0x00; funct = 0x08; rs = atoi(res1);
        sprintf(binario, "%s%s000000000000000%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(funct, 6));
    } else if (strcmp(comando, "addi") == 0) {
        opcode = 0x08; rs = atoi(res2); rt = atoi(res1); imediato = atoi(res3);
        sprintf(binario, "%s%s%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(imediato, 16));
    } else if (strcmp(comando, "beq") == 0) {
        opcode = 0x04; rs = atoi(res1); rt = atoi(res2); imediato = atoi(res3);
        sprintf(binario, "%s%s%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(imediato, 16));
    } else if (strcmp(comando, "bne") == 0) {
        opcode = 0x05; rs = atoi(res1); rt = atoi(res2); imediato = atoi(res3);
        sprintf(binario, "%s%s%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(imediato, 16));
    } else if (strcmp(comando, "lw") == 0) {
        opcode = 0x23; rs = atoi(res3); rt = atoi(res1); imediato = atoi(res2);
        sprintf(binario, "%s%s%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(imediato, 16));
    } else if (strcmp(comando, "sw") == 0) {
        opcode = 0x2b; rs = atoi(res3); rt = atoi(res1); imediato = atoi(res2);
        sprintf(binario, "%s%s%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(rs, 5),
            decimal_para_binario(rt, 5),
            decimal_para_binario(imediato, 16));
    } else if (strcmp(comando, "j") == 0) {
        opcode = 0x02; endereco_j = atoi(res1);
        sprintf(binario, "%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(endereco_j, 26));
    } else if (strcmp(comando, "jal") == 0) {
        opcode = 0x03; endereco_j = atoi(res1);
        sprintf(binario, "%s%s",
            decimal_para_binario(opcode, 6),
            decimal_para_binario(endereco_j, 26));
    } else {
        printf("Instrução \"%s\" não reconhecida.\n\n", comando);
        exit(EXIT_FAILURE);
    }

    return binario;
}

// Função para escrever o binário em um arquivo MIF
void escreverBinarioEmBlocos(FILE *mif_fp, char *binario) {
    int comprimento = strlen(binario);

    // Escrever em blocos de 8 bits
    for (int i = 0; i < comprimento; i += 8) {
        fprintf(mif_fp, "%.8s\n", binario + i);
    }
}

// Função para ler o arquivo de entrada
FILE *lerArquivo(char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "r");
    if (!fp) {
        printf("Não foi possível abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Função para criar o arquivo MIF
FILE *criarArquivoMIF(char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        printf("Não foi possível criar o arquivo\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <arquivo_entrada> <arquivo_saída>\n", argv[0]);
        return 1;
    }

    FILE *fp = lerArquivo(argv[1]);
    FILE *mif_fp = criarArquivoMIF(argv[2]);

    char linha[BUFFER], comando[BUFFER], res1[BUFFER], res2[BUFFER], res3[BUFFER];

    while (fgets(linha, BUFFER, fp)) {
        // Ignorar linhas em branco ou comentários
        if (linha[0] == '\n' || linha[0] == '#') continue;

        if (sscanf(linha, "%s %s %s %s", comando, res1, res2, res3) < 1) continue;

        char *codigo_binario = obterCodigoBinario(comando, res1, res2, res3);

        escreverBinarioEmBlocos(mif_fp, codigo_binario);

        free(codigo_binario);
    }

    fclose(fp);
    fclose(mif_fp);

    printf("Conversão concluída!\n");

    return 0;
}

