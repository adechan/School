package controllers;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import entity.Movie;
import entity.Person;

import java.io.Serializable;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import javax.persistence.EntityNotFoundException;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Root;

/**
 *
 * @author Andreea Rindasu
 */
public class MovieController implements Serializable {

    public MovieController(EntityManagerFactory emf) {
        this.emf = emf;
    }
    private EntityManagerFactory emf = null;

    public EntityManager getEntityManager() {
        return emf.createEntityManager();
    }

    public void create(Movie movie) {
        EntityManager em = null;
        try {
            em = getEntityManager();
            em.getTransaction().begin();
            em.persist(movie);
            em.getTransaction().commit();
        } finally {
            if (em != null) {
                em.close();
            }
        }
    }

    public void edit(Movie movie) throws Exception {
        EntityManager em = null;
        try {
            em = getEntityManager();
            em.getTransaction().begin();
            movie = em.merge(movie);
            em.getTransaction().commit();
        } catch (Exception ex) {
            String msg = ex.getLocalizedMessage();
            if (msg == null || msg.length() == 0) {
                Long id = movie.getId();
                if (findMovie(id) == null) {
                    throw new Exception("The movie with id " + id + " no longer exists.");
                }
            }
            throw ex;
        } finally {
            if (em != null) {
                em.close();
            }
        }
    }

    public void destroy(Long id) throws Exception {
        EntityManager em = null;
        try {
            em = getEntityManager();
            em.getTransaction().begin();
            Movie movie;
            try {
                movie = em.getReference(Movie.class, id);
                movie.getId();
            } catch (EntityNotFoundException enfe) {
                throw new Exception("The movie with id " + id + " no longer exists.", enfe);
            }
            em.remove(movie);
            em.getTransaction().commit();
        } finally {
            if (em != null) {
                em.close();
            }
        }
    }

    public List<Movie> findMovieEntities() {
        return findMovieEntities(true, -1, -1);
    }

    public List<Movie> findMovieEntities(int maxResults, int firstResult) {
        return findMovieEntities(false, maxResults, firstResult);
    }

    private List<Movie> findMovieEntities(boolean all, int maxResults, int firstResult) {
        EntityManager em = getEntityManager();
        try {
            CriteriaQuery cq = em.getCriteriaBuilder().createQuery();
            cq.select(cq.from(Movie.class));
            Query q = em.createQuery(cq);
            if (!all) {
                q.setMaxResults(maxResults);
                q.setFirstResult(firstResult);
            }
            return q.getResultList();
        } finally {
            em.close();
        }
    }

    public Movie findMovie(Long id) {
        EntityManager em = getEntityManager();
        try {
            return em.find(Movie.class, id);
        } finally {
            em.close();
        }
    }

    public int getMovieCount() {
        EntityManager em = getEntityManager();
        try {
            CriteriaQuery cq = em.getCriteriaBuilder().createQuery();
            Root<Movie> rt = cq.from(Movie.class);
            cq.select(em.getCriteriaBuilder().count(rt));
            Query q = em.createQuery(cq);
            return ((Long) q.getSingleResult()).intValue();
        } finally {
            em.close();
        }
    }
        
    public Movie findByName(String movieName) {
        EntityManager em = emf.createEntityManager();
        Query query = em.createQuery("select t from Movie t where t.name like :name");
        List movies = query.setParameter("name", movieName).getResultList();
        em.close();
                
        return movies.isEmpty() ? null : (Movie)movies.get(0);
    }

    
	public void create(String string, Person findByName) {
		// TODO Auto-generated method stub
		
	}

	public void print() {
		// TODO Auto-generated method stub
		
	}
    
}
