var eleccionJugador1 = null;
var eleccionJugador2 = null;

function jugar(jugador, eleccion) {
    if (jugador === 'jugador1') {
        eleccionJugador1 = eleccion;
        document.getElementById("jugador1").innerHTML = "<h2>Jugador 1 eligió: " + eleccion + "</h2><img class='hand' src='" + eleccion + ".png' alt='" + eleccion + "'>";
    } else {
        eleccionJugador2 = eleccion;
        document.getElementById("jugador2").innerHTML = "<h2>Jugador 2 eligió: " + eleccion + "</h2><img class='hand' src='" + eleccion + ".png' alt='" + eleccion + "'>";

        var resultado = determinarResultado();
        document.getElementById("resultado").textContent = resultado;

        if (resultado.includes("gana")) {
            mostrarFuegosArtificiales();
            mostrarGanador(resultado);
        }
    }
}

function determinarResultado() {
    var resultado = "";

    if (eleccionJugador1 === eleccionJugador2) {
        resultado = "¡Empate!";
    } else if (
        (eleccionJugador1 === "piedra" && eleccionJugador2 === "tijera") ||
        (eleccionJugador1 === "papel" && eleccionJugador2 === "piedra") ||
        (eleccionJugador1 === "tijera" && eleccionJugador2 === "papel")
    ) {
        resultado = "¡Jugador 1 gana!";
    } else {
        resultado = "¡Jugador 2 gana!";
    }

    return resultado;
}

function mostrarFuegosArtificiales() {
    var fireworksContainer = document.getElementById("fireworks-container");
    fireworksContainer.style.zIndex = "2";
}

function mostrarGanador(resultado) {
    var ganador = document.getElementById("ganador");
    ganador.textContent = resultado;
    ganador.style.display = "block";
    ganador.classList.add("ganador-animado");

    for (let i = 0; i < 100; i++) {
        setTimeout(function () {
            crearConfeti();
        }, i * 30);
    }
}

function crearConfeti() {
    var confeti = document.createElement("div");
    confeti.classList.add("confeti");
    confeti.style.left = Math.random() * 100 + "vw";
    document.getElementById("fireworks-container").appendChild(confeti);

    confeti.addEventListener("animationend", function () {
        confeti.remove();
    });
}
