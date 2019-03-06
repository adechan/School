-- if else
set serverouput on;
accept x prompt 'Please enter your number: ';
declare 
  numar number(5);
  x number(5);
begin
  numar := &x;
  if (numar mod 2 = 0)
    then 
    dbms_output.put_line('numar par');
  else
    dbms_output.put_line('numar impar');
  end if;
end;

-- if elsif else
declare 
  numar number(5) := 50;
begin
  if (numar < 10) 
  then 
    dbms_output.put_line('numar mai mic decat 10');
  elsif (numar > 80)
  then 
    dbms_output.put_line('numar mai mare decat 80');
  else 
    dbms_output.put_line('numar intre 10 si 80');
  end if;
end;

-- bucle
declare
  v_contor INTEGER := 0;
begin 
  while (v_contor < 10) LOOP
    v_contor := v_contor + 1;
    dbms_output.put_line(v_contor);
  end LOOP;
end;

-- bucle FOR
-- descrescator: FOR v_contor IN REVERSE 1..10 LOOP
declare 
  v_contor INTEGER := 0;
begin 
  for v_contor in 5..10 LOOP
    dbms_output.put_line(v_contor);
  end loop;
end;

-- EXIT: pentru a forta iesirea dintr-o structura
declare
  v_contor1 INTEGER;
  v_contor2 INTEGER;
begin
  <<eticheta>>
  for v_contor1 in 1..5 LOOP
    for v_contor2 in 10..20 LOOP
      dbms_output.put_line(v_contor1 || '-' || v_contor2);
      exit eticheta when ((v_contor1 = 3) and (v_contor2 = 17));
    end loop;
  end loop;
end;

-- CONTINUE: pentru a sari peste codul ramas in bucla
declare
  v_contor1 INTEGER;
  v_contor2 INTEGER;
begin
  <<eticheta>>
  for v_contor1 in 1..5 LOOP
    for v_contor2 in 10..20 LOOP
      CONTINUE WHEN ((v_contor1=3) AND (v_contor2=13));
      dbms_output.put_line(v_contor1 || '-' || v_contor2);
      exit eticheta when ((v_contor1 = 3) and (v_contor2 = 17));
    end loop;
  end loop;
end;

-- GOTO: face saltul la o anumita eticheta
begin 
  goto eticheta;
  dbms_output.put_line('nu se afiseaza');
  <<eticheta>>
  dbms_output.put_line('se afiseaza');
end;

-- CURSOARE

-- CURSOR IMPLICIT: sql%found, sql%notfound, sql%rowcount
-- cursor: memoria in care este pastrata o interogare impreuna
-- cu datele pe care le utilieaza 
declare 
  v_randuri INTEGER;
begin
  update studenti set bursa = bursa + 10 where bursa > 300;
  if (sql%found)
  then 
    dbms_output.put_line('am marit bursa la ' || sql%rowcount || ' studenti');
  else 
    dbms_output.put_line('nimanui nu i s-a marit bursa');
  end if;
end;

-- CURSOR EXPLICIT
-- utilizate atunci cand interogarile pe care le efectuam asupra
-- bazei de date vor returna mai mult de un singur rand si
-- permit procesarea informatiilor din rezultat linie cu linie

declare
  cursor lista_studenti_bursieri IS
    select nume, prenume from studenti where bursa is not null;
  v_nume studenti.nume%type;
  v_prenume studenti.prenume%type;
begin
  open lista_studenti_bursieri;
  loop
    fetch lista_studenti_bursieri into v_nume, v_prenume;
    exit when lista_studenti_bursieri%notfound;
    dbms_output.put_line(v_nume || ' ' || v_prenume);
  end loop;
  close lista_studenti_bursieri;
end;


declare 
  cursor lista_studenti IS
    select * from studenti;
  v_std_linie lista_studenti%rowtype;
begin
  open lista_studenti;
  loop
    fetch lista_studenti into v_std_linie;
    exit when lista_studenti%notfound;
    dbms_output.put_line(v_std_linie.nume || ' ' || v_std_linie.data_nastere );
  end loop;
  close lista_studenti;
end;

DECLARE
   CURSOR lista_studenti  IS
       SELECT * FROM studenti;
BEGIN
    FOR v_std_linie IN lista_studenti LOOP     
        DBMS_OUTPUT.PUT_LINE(v_std_linie.nume||' '|| v_std_linie.data_nastere);
    END LOOP;  
END;


declare 
  cursor lista_studenti_bursieri (p_bursa studenti.bursa%type, p_an studenti.an%type) IS
    select nume, prenume from studenti where bursa > p_bursa and an > p_an;
  v_std_linie lista_studenti_bursieri%rowtype;
begin 
  open lista_studenti_bursieri(300, 2);
  loop
    fetch lista_studenti_bursieri into v_std_linie;
    exit when lista_studenti_bursieri%notfound;
    dbms_output.put_line(v_std_linie.nume || ' ' || v_std_linie.prenume);
  end loop;
  close lista_studenti_bursieri;
end;

-- CURSOR explicit cu clauza FOR UPDATE:
-- daca in timpul procesarii cursorului dorim sa modificam o linie

declare 
  cursor update_note IS
    select * from note for update of valoare NOWAIT;
begin 
  for v_linie in update_note LOOP
    if (v_linie.valoare < 5)
    then 
      update note set valoare = 5 where current of update_note;
    end if;
  end loop;
end;