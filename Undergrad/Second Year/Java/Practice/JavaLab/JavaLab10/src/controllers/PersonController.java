/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controllers;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;

import entity.Person;
import java.util.List;

/**
 *
 * @author Andreea Rindasu
 */
public class PersonController {
    private EntityManagerFactory emf;
    public PersonController(EntityManagerFactory emf) {
        this.emf = emf;
    }

    /**
     *
     * @param string
     */
    public void create(String string) {
        EntityManager em;
        em = emf.createEntityManager();
        em.getTransaction().begin();
        em.persist(string);
        em.getTransaction().commit();
        em.close();
    }

    /**
     *
     * @param personName
     * @return
     */
    public Person findByName(String personName) {
        EntityManager em;
        em = emf.createEntityManager();
        Query query = em.createQuery("select t from Person t where t.name like :name");
        List persons = query.setParameter("name", personName).getResultList();
		em.close();
                
        if (persons.isEmpty())
            return null;
        
        return (Person)persons.get(0);
    }

	public void print() {
		// TODO Auto-generated method stub
		
	}

	public void create(Person person) {
		// TODO Auto-generated method stub
		
	}
}
