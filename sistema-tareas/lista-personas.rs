// Definir una estructura de Persona
struct Persona {
    nombre: String,
    edad: u32,
}

fn main() {
    // Crear una lista de personas
    let mut lista_personas: Vec<Persona> = Vec::new();

    // Agregar personas a la lista
    lista_personas.push(Persona { nombre: "Juan".to_string(), edad: 30 });
    lista_personas.push(Persona { nombre: "Maria".to_string(), edad: 25 });
    lista_personas.push(Persona { nombre: "Pedro".to_string(), edad: 40 });

    // Imprimir la lista de personas
    for persona in &lista_personas {
        println!("Nombre: {}, Edad: {}", persona.nombre, persona.edad);
    }
}
