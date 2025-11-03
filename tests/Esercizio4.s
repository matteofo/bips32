# Scrivere un programma che ricerchi un numero
# in un array di numeri interi, in particolare: 
# $a0 contenga l’indirizzo d'inizio dell’array 
# $a1 contenga il numero di elementi dell’array 
# $a2 contenga il numero da cercare 

# Il programma deve impostare il contenuto del registro
# $t9 a 1 se trova il numero, a 0 altrimenti. 
# Per la scrittura del programma, 
# utilizzare un array arbitrario memorizzandolo in memoria
    .data
array: .word 1, 2, 4, 6, 7, 8, 20, 120, 440
msg: .asciiz "elemento non trovato!\n"
    .text
    .globl main
main:
    # carico come da consegna
    la $a0, array # indirizzo array 
    li $a1, 9 # numero elementi
    li $a2, 120 # numero da trovare

    li $t1, 0 # contatore indice
    li $t9, 0 # 1 se trovato, 0 altrimenti

search:
    lw $t0, 0($a0) # carichiamo l'elemento dell'array
    beq $t0, $a2, found # se elem = $a2, vado alla fine

    addi $a0, $a0, 4 # prossimo
    addi $t1, $t1, 1

    bgt $t1, $a1, errore # se contatore > $a1, errore
    j search # altrimenti, ripeto la ricerca

errore: # stampo errore
    la $a0, msg
    li $v0, 4
    syscall

fine:
    # fine del programma
    li $v0, 10
    syscall

found:
    li $t9, 1 # elemento trovato!

    # stampo l'indice
    move $a0, $t1
    li $v0, 1
    syscall

    # stampo il numero
    move $a0, $a2
    li $v0, 1
    syscall

    j fine