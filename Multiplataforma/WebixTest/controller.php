<?php
    $accion = $_POST['Accion'];
    if ( $accion == "Guardar") {
        $mysqli = new mysqli("localhost", "alumnos", "app.2023", "gama");
        $sentencia = $mysqli->prepare("insert into Peliculas
                                        (id, nivel, titulo, anio, votos)
                                        values (0, ?, ?, ?, ?)");        
        $sentencia->bind_param("isii", $_POST['nivel'], $_POST['titulo'], $_POST['anio'], $_POST['votos']);
        $sentencia->execute();        
    }else if ( $accion == "Borrar") {
        $ids = $_POST['Id'];
        $ids = str_replace("[","",$ids);
        $ids = str_replace("]","",$ids);
        $ids = explode(",",$ids);
        $mysqli = new mysqli("localhost", "alumnos", "app.2023", "gama");
        $sentencia = $mysqli->prepare("delete from Peliculas where id = (?)");        
        foreach($ids as &$id){
            $sentencia->bind_param("i", $id);
            $sentencia->execute();        
        }
    }
?>