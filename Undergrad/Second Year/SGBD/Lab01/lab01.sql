BEGIN
   DBMS_OUTPUT.PUT_LINE('Maine:' || (SYSDATE+1));
END;

set serveroutput on;
DECLARE
      v_mesaj VARCHAR2(50) := 'Salutare, lume !';
BEGIN
      DBMS_OUTPUT.PUT_LINE('Mesaj: ' || v_mesaj);
END;

set serveroutput on;
DECLARE
   a NUMBER := 10;
   b NUMBER := 4;
BEGIN
   DBMS_OUTPUT.PUT_LINE('Suma: ' || (a+b));
   DBMS_OUTPUT.PUT_LINE('Diferenta: ' || (a-b));
   DBMS_OUTPUT.PUT_LINE('Produsul: ' || (a*b));
   DBMS_OUTPUT.PUT_LINE('Impartirea: ' || (a/b));
   DBMS_OUTPUT.PUT_LINE('Exponentierea: ' || (a ** b)); -- nu exista in SQL
END;

set serveroutput on;
DECLARE
   a NUMBER := 10;
   b NUMBER := 4;
BEGIN
   IF (a>b) 
      THEN DBMS_OUTPUT.PUT_LINE(a || '>' || b);
      ELSE DBMS_OUTPUT.PUT_LINE(b || '>=' || a);
   END IF;
   IF (a != b) -- se poate utiliza si <> sau ~=
      THEN DBMS_OUTPUT.PUT_LINE('Cele doua valori sunt diferite.');
      ELSE DBMS_OUTPUT.PUT_LINE('Cele doua valori sunt egale');
   END IF;   
END;


set serveroutput on;
DECLARE
   a NUMBER := TRUNC(DBMS_RANDOM.VALUE(0,100)); -- eliminati atribuirea pentru a fi NULL;
BEGIN
   IF (a IS NOT NULL) 
      THEN 
         IF (a BETWEEN 20 AND 80)
              THEN DBMS_OUTPUT.PUT_LINE(a || ' este intre 20 si 80');
              ELSE DBMS_OUTPUT.PUT_LINE(a || ' NU este intre 20 si 80');
         END IF;     
      ELSE DBMS_OUTPUT.PUT_LINE('Valoare nula');
   END IF;
END;


DECLARE
   v_valoare_nota_maxima note.valoare%TYPE;
BEGIN   
   SELECT MAX(valoare) INTO v_valoare_nota_maxima FROM note; 
   DBMS_OUTPUT.PUT_LINE('Nota maxima: ' || v_valoare_nota_maxima);
END;



DECLARE
   v_valoare_nota_minima note.valoare%TYPE;
BEGIN   
   SELECT MIN(valoare) INTO v_valoare_nota_minima FROM note; 
   DBMS_OUTPUT.PUT_LINE('Nota minima: ' || v_valoare_nota_minima);
END;



BEGIN
     DBMS_OUTPUT.PUT_LINE(TO_CHAR(SYSDATE,'Month DD, YYYY'));
END;
