# Cambios importantes 
- Agregue contadorCompras al controladorVentas
>Ahora compra no tiene productos en promocion y si tiene un map de compras por producto
-Compras tiene int id y string cliente

- Cambie en promocion el set<ProductoEnPromocion> por un map<int,ProductoEnPromocion>
> ProductoEnPromocion tiene ahora un puntero a la Promocion a la que pertenece (haganme acordar de borrarlo :3)


- Cambiamos nickname por nickname como ya lo teniamos? 
- Dato en usuario la primer entrada es contrasenia no nickname, lo cambio por intuicion?
- Cambie los vectores de ControladorUsuarios por maps

## Cambios ya implementados
- Descuento: Lo calculo o no? como me viene en porcentaje o como? yo puse float

  
- En controladorVentas cambie el set de vendedores por un map y la key es el nickname del vendedor, esto hace que la busqueda cuando tenemos el nombre del vendedor sea O(1)
- Pongo el toString en Usuario o directamente en vendedor? (no se si Cliente necesita un toString)
- Cambie el siguiente set de este datatype por un set<ProductoEnPromocion*>
  
  ![image](https://github.com/MAST0dontE/prueba/assets/70988692/f8a19a4c-eaa3-4b7d-bfbb-045780471262)

- Vendedor no deberia tener un set de productos en lugar de un set de DTInfoProducto?
- Le agregue mas datos a DTinfoPromocion (datos de la promocion en si)

![image](https://github.com/MAST0dontE/prueba/assets/70988692/b7421180-c0d6-4976-a080-5bbe6f9a0b61)

  

# ANTES DE HACER COMMIT VEAN QUE COMPILE
  


# Casos de uso
## Leo
- [ ] Listado de usuarios
- [ ] Alta de producto
- [ ] Consulta a notificaciones 

## Luki
- [ ] Consultar producto
- [ ] Crear promoción
- [ ] Suscribirse 

## Ori
- [ ] Consultar promocion
- [ ] Realizar compra
- [ ] Eliminar suscripción

## Santi
- [ ] Dejar comentario
- [ ] Eliminar comentario
- [ ] santi se la come

## Cyn
- [ ] Enviar producto
- [ ] Expediente de Usuario
- [ ] Alta de usuario

![WhatsApp Image 2024-06-11 at 12 28 20 AM|100](https://github.com/MAST0dontE/prueba/assets/70988692/fa494328-6a6b-4ff3-b37b-ca3bc61a7ad2)

