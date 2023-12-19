<?php
    $mysqli = new mysqli("localhost", "alumnos", "app.2023", "gama");
    $sentencia = $mysqli->prepare("select * from Peliculas where 1=?");  
    $var = 1;      
    $sentencia->bind_param("i", $var);
    $sentencia->execute();
    $resultados = $sentencia->get_result();
    $arr = array();
    while($fila = mysqli_fetch_assoc($resultados)){
        $arr[] = $fila;
    }
    echo json_encode($arr);
?>