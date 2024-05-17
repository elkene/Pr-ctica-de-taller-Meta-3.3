// Clase abstracta Publicacion
public abstract class Publicacion {
    protected String titulo;
    protected String autor;
    protected int anioPublicacion;

    public Publicacion(String titulo, String autor, int anioPublicacion) {
        this.titulo = titulo;
        this.autor = autor;
        this.anioPublicacion = anioPublicacion;
    }

    // Método abstracto
    public abstract String obtenerInformacion();
}

// Interfaz Prestamo
public interface Prestamo {
    void prestar();
    void devolver();
}

// Clase concreta Libro que hereda de Publicacion e implementa Prestamo
public class Libro extends Publicacion implements Prestamo {
    private String ISBN;
    private int numeroPaginas;

    public Libro(String titulo, String autor, int anioPublicacion, String ISBN, int numeroPaginas) {
        super(titulo, autor, anioPublicacion);
        this.ISBN = ISBN;
        this.numeroPaginas = numeroPaginas;
    }

    // Implementación del método abstracto de Publicacion
    @Override
    public String obtenerInformacion() {
        return "Título: " + titulo + ", Autor: " + autor + ", Año: " + anioPublicacion + 
               ", ISBN: " + ISBN + ", Páginas: " + numeroPaginas;
    }

    // Implementación de los métodos de la interfaz Prestamo
    @Override
    public void prestar() {
        System.out.println("El libro '" + titulo + "' ha sido prestado.");
    }

    @Override
    public void devolver() {
        System.out.println("El libro '" + titulo + "' ha sido devuelto.");
    }

    // Métodos adicionales (opcional)
    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public int getNumeroPaginas() {
        return numeroPaginas;
    }

    public void setNumeroPaginas(int numeroPaginas) {
        this.numeroPaginas = numeroPaginas;
    }
}

// Clase principal para probar la implementación
public class Biblioteca {
    public static void main(String[] args) {
        Libro libro = new Libro("El Quijote", "Miguel de Cervantes", 1605, "1234567890", 500);
        
        System.out.println(libro.obtenerInformacion());
        libro.prestar();
        libro.devolver();
    }
}
