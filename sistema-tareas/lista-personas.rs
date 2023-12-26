struct Persona {
    nombre: String,
    edad: u32,
}

fn main() {
    // Creamos una lista de personas
    let mut lista_personas = Vec::new();

    // Agregamos algunas personas a la lista
    lista_personas.push(Persona {
        nombre: String::from("Juan"),
        edad: 30,
    });
    lista_personas.push(Persona {
        nombre: String::from("María"),
        edad: 25,
    });
    lista_personas.push(Persona {
        nombre: String::from("Pedro"),
        edad: 35,
    });

    // Iteramos sobre la lista e imprimimos la información de cada persona
    for persona in &lista_personas {
        println!("Nombre: {}, Edad: {}", persona.nombre, persona.edad);
    }
}
