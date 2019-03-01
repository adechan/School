/*
Date de la tastatura 2 numere a si b :
Dupa ce sortam catalogul in ordine alfabetica vrem 
sa preluam studentii care sunt pe pozitiile a si b. 

Afisati:
nume prenume media st1
nume prenume media st2
nume prenume media cu cel mai mare 

NUMBER(a,b) : number with a zecimals in total and b zecimals after ','
COUNT(*) : returns number of rows that matches the criteria
*/

set serveroutput on;
declare 
v_pozitie_a INTEGER := &i_pozitie_a;
v_pozitie_b INTEGER := &i_pozitie_b;
v_pozitie_maxima INTEGER;
v_nume_stud1 studenti.nume%TYPE;
v_nume_stud2 studenti.nume%TYPE;
v_prenume_stud1 studenti.prenume%TYPE;
v_prenume_stud2 studenti.prenume%TYPE;
v_medie_stud1 NUMBER(5,2);
v_medie_stud2 NUMBER(5,2);

begin

select count(nume) into v_pozitie_maxima from studenti;
if ((v_pozitia_a > v_pozitie_maxima) or (v_pozitie_b > v_pozitie_maxima))
then
	dbms_output.put_line('Eroare, pozitie mai mare decat numarul de studenti.');
else
	select nume, prenume into v_nume_stud1, v_prenume_stud1 from 
	(select nume, prenume, rownum as rh from 
	(select nume, prenume from studenti order by nume asc))
	where rh = v_pozitie_a;
	
	select nume, prenume into v_nume_stud2, v_prenume_stud2 from
	(select nume, prenume, rownum as rh from
	(select nume, prenume from studenti order by nume asc))
	where rh = v_pozitie_b;
	
	select avg(valoare) into v_medie_stud1 from studenti s
	join note n on s.id = n.id_student and
	s.nume = v_nume_stud1 and
	s.prenume = v_prenume_stud1;
	
	select avg(valoare) into v_medie_stud2 from studenti s
	join note n on s.id = n.id_student and 
	s.nume = v_nume_stud2 and
	s.prenume = v_prenume_stud2;
	
	dbms_output.put_line('Studentul de pe pozitia ' || v_pozitie_a || ': ' || 
	v_nume_stud1 || ' ' || v_prenume_stud1 || ' ' || v_medie_stud1);
	
	dbms_output.put_line('Studentul de pe pozitia ' || v_pozitie_b || ': ' ||
	v_nume_stud2 || ' ' || v_prenume_stud2 || ' ' || v_medie_stud2);
	
	if (v_medie_stud1 <> v_medie_stud2)
	then
		if(v_medie_stud1 > v_medie_stud2)
		then 
			dbms_output.put_line('Studentul cu media mai mare este: ' || v_nume_stud1 ||
			' ' || v_prenume_stud1 || ' ' || v_medie_stud1);
		else
			dbms_output.put_line('Studentul cu media mai mare este: ' || v_nume_stud2 ||
			' ' || v_prenume_stud2 || ' ' || v_medie_stud2);
		end if;
	else 
		dbms_output.put_line('Studentii au aceeasi medie: ' || v_nume_stud1);
	end if;
end if;
end;

