# h5
<h3> Double Hashing ve Quadratic Hashing Algoritmalarının Analizi:  </h3>

 <b> Double Hashing Algoritması:  </b>
Double hashing, ikinci bir hash fonksiyonu kullanarak çakışmaların çözüldüğü bir açık adresleme yöntemidir. İlk önce ana hash fonksiyonu kullanılarak bir indeks hesaplanır, eğer bu indeks zaten dolu ise ikinci hash fonksiyonu kullanılarak bir adım atlanır ve yeni bir indeks hesaplanır. Bu işlem, boş bir hücre bulunana kadar tekrarlanır.

 <b> Quadratic Hashing Algoritması:  </b>
Quadratic hashing de bir açık adresleme yöntemidir. Çakışma durumunda, her adımda bir kare artırılarak yeni bir indeks hesaplanır. Eğer bu indeks dolu ise bir sonraki adımda iki kare artırılarak yeni bir indeks hesaplanır. Bu işlem, boş bir hücre bulunana kadar tekrarlanır.

Tablo boyutu arttıkça, çakışmaların oluşma olasılığı azalır, ancak çakışmaların çözülmesi de daha fazla zaman alır.