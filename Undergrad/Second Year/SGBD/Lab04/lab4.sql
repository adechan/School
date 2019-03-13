set serveroutput on;
DECLARE 
    TYPE MyTab IS TABLE OF NUMBER INDEX BY VARCHAR2(10);
    varsta MyTab;
BEGIN
   varsta('Gigel') := 3;
   varsta('Ionel') := 4;
   DBMS_OUTPUT.PUT_LINE('Varsta lui Gigel este ' || varsta('Gigel'));
   DBMS_OUTPUT.PUT_LINE('Varsta lui Ionel este ' || varsta('Ionel'));
END;

DECLARE 
    TYPE MyTab IS TABLE OF studenti%ROWTYPE INDEX BY PLS_INTEGER;
    linii MyTab;
BEGIN
    SELECT * INTO linii(0) FROM studenti WHERE ROWNUM = 1;
    DBMS_OUTPUT.PUT_LINE(linii(0).prenume);
END;


DECLARE 
    TYPE MyTab IS TABLE OF number INDEX BY varchar2(20);
    linii MyTab;  
BEGIN
    linii(sysdate) := 123;
    DBMS_OUTPUT.PUT_LINE(linii(sysdate));
END;


DECLARE 
    TYPE MyTab IS TABLE OF NUMBER INDEX BY VARCHAR2(10);
    varsta MyTab;
BEGIN
   varsta('Gigel') := 3;
   varsta('Ionel') := 4;
   varsta('Maria') := 6;
   
   DBMS_OUTPUT.PUT_LINE('Numar de elemente in lista: ' || varsta.COUNT);
   
   DBMS_OUTPUT.PUT_LINE('Prima cheie din lista: ' || varsta.FIRST);
   DBMS_OUTPUT.PUT_LINE('Ultima cheie din lista: ' || varsta.LAST);

   DBMS_OUTPUT.PUT_LINE('Inaintea lui Ionel in lista: ' || varsta.PRIOR('Ionel'));
   DBMS_OUTPUT.PUT_LINE('Dupa Ionel in lista: ' || varsta.NEXT('Ionel'));
      
   varsta.DELETE('Maria');   
   DBMS_OUTPUT.PUT_LINE('Dupa Ionel in lista: ' || varsta.NEXT('Ionel'));   
END;


DECLARE
    TYPE prenume IS TABLE OF varchar2(10);
    student prenume;
BEGIN
    student := prenume('Gigel', 'Ionel');
    for i in student.first..student.last loop
       DBMS_OUTPUT.PUT_LINE(i||' - '||student(i));    
    end loop;
END;


DECLARE
    TYPE prenume IS TABLE OF varchar2(10);
    student prenume;
BEGIN
    student := prenume('Gigel', 'Ionel', 'Maria');  
    student.EXTEND(4,2); -- copii elementul al doilea de 4 ori
    student.delete(2); -- sterg elementul al doilea
    for i in student.first..student.last loop
        if student.exists(i) then -- daca incerc sa afisez ceva ce nu exista se va produce o eroare
           DBMS_OUTPUT.PUT_LINE(i||' - '||student(i));  -- afisam pozitia si valoarea
        end if;
    end loop;
END;


set serveroutput on;
DECLARE
    TYPE prenume IS TABLE OF varchar2(10);
    student prenume := prenume();
    student_err prenume;
BEGIN  
    student.EXTEND; -- merge ok
    student_err.EXTEND; -- da eroare pentru ca este null (sau nu a fost initializat)
END;


DECLARE 
   CURSOR curs IS SELECT * FROM studenti;
   TYPE linie_student IS TABLE OF curs%ROWTYPE;
   lista_studenti linie_student;
BEGIN
   open curs;
   SELECT * BULK COLLECT INTO lista_studenti FROM studenti;
   close curs;
    for i in lista_studenti.first..lista_studenti.last loop
        if lista_studenti.exists(i) then -- daca incerc sa afisez ceva ce nu exista se va produce o eroare
           DBMS_OUTPUT.PUT_LINE(i||' - '||lista_studenti(i).nume);  -- afisam pozitia si valoarea
        end if;
    end loop;   
    DBMS_OUTPUT.PUT_LINE('Numar studenti: '||lista_studenti.COUNT);
END;


GRANT CREATE TYPE TO STUDENT; -- aceasta linie se executa din "SYS as SYSDBA"

CREATE OR REPLACE TYPE lista_prenume AS TABLE OF VARCHAR2(10);
/
CREATE TABLE persoane (nume varchar2(10), 
       prenume lista_prenume)
       NESTED TABLE prenume STORE AS lista;
/       

INSERT INTO persoane VALUES('Popescu', lista_prenume('Ionut', 'Razvan'));
INSERT INTO persoane VALUES('Ionescu', lista_prenume('Elena', 'Madalina'));
INSERT INTO persoane VALUES('Rizea', lista_prenume('Mircea', 'Catalin'));
/
SELECT * FROM persoane;

-- mai multe operatii direct cu tabelele interne dintr-un tabel gasiti in linkurile de la inceputul acestei pagini.

DECLARE
  TYPE varr IS VARRAY(5) OF varchar2(10);
  orase varr;
BEGIN
  orase := varr('Iasi', 'Bacau', 'Suceava', 'Botosani');
  DBMS_OUTPUT.PUT_LINE('Numar orase: '||orase.COUNT);
  orase.TRIM;
  FOR i IN orase.FIRST..orase.LAST LOOP
     DBMS_OUTPUT.PUT_LINE(orase(i));
  END LOOP;
  
  orase.EXTEND(2);
  orase(4):='Sibiu';
  orase(5):='Brasov';
  DBMS_OUTPUT.PUT_LINE('Dupa adaugare:');
  FOR i IN orase.FIRST..orase.LAST LOOP
     DBMS_OUTPUT.PUT_LINE(orase(i));
  END LOOP;  
END;

CREATE TABLE minions (culoare varchar2(20), numar_ochi number(3), nume varchar2(20));
 /
DECLARE
   TYPE minion IS RECORD(
      culoare varchar2(20) := 'Galben', 
      numar_ochi number(3), 
      nume varchar2(20)
      );
   v_minion minion;   
BEGIN      
   v_minion.culoare:='Galben';
   v_minion.numar_ochi := 2;
   v_minion.nume:='Kevin';
   INSERT INTO MINIONS VALUES V_MINION;
   DBMS_OUTPUT.PUT_LINE(v_minion.culoare);
END;