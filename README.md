#Fonctionnement de l'algorythme#

##ENTREPRISES (NOM, TRÉSORERIE, CHARGES/JOUR, POURCENTAGE MARGE) :##
"La Mine" : Fourni toutes les matières premières nécessaire à la fabrication des produits. Ne vend qu'une certaines quantité par jour pour toute les entreprises
	
	La Mine (845 371 €, 5 912 €, 20 %): 		Bois, Fil de cuivre, Inox, Gaines plastique, Granulés plastique, Résine, Tissus, Mousse, Aluminium, Verre
	Verrutil (182 347 €, 1 061 €, 19 %) :		Écrans, Fenêtres, Abris de jardin, Lunettes
	Heavy Metal (550 645 €, 3 418 €, 16 %) : 	Vis, Circuits imprimés, Fil électrique, Ordinateurs, Écrans, Fenêtres
	Fantastic Plastic (198 269 €, 1 982 €, 18 %) :	Circuits imprimés, Coques ordinateurs, Lunettes, Ordinateurs
	Fabric Textil (129 921 €, 1 145 €, 21 %) : 	Matelas, Lits, Canapés, Fauteuils
	Super Bois (415 326 €, 2 987 €, 17 %) : 	Bureau, Fauteuils, Abris de jardin, Lits, Canapés


##PRODUITS :##

	Fil électrique : Fil de cuivre, Gaines plastique
	Circuit imprimés : Résine, Fil de cuivre
	Écrans : Circuits Imprimes, Fil de cuivre, Verre, Granules plastique, Vis
	Vis : Inox
	Fenêtres : Aluminium, Verre, Vis
	Abris de jardin : Bois, Vis, Fenêtre
	Matelas : Tissus, Mousse
	Bureau : Plaque de bois, Vis, Acier
	Coques ordinateurs : Granules plastique
	Ordinateurs : Ecran, Circuits imprimes, Fil de cuivre, Vis
	Lits : Bois, Vis, Matelas
	Canapés : Bois, Tissus,Mousse
	Lunettes : Verre, Inox
	Fauteuils : Tissus, Mousse, Granules Plastique, Vis


##FABRICATION SOUS-PRODUITS :##

	Entreprise veut fabriquer "quantité" de "nomProduit"
	Achète "quantité" de "nomMatière" à "LaMine" pour "montant"
	Soustraction de "montant" - "trésorerie"
	Prix de vente = "montant" + "chargesEntreprises" + "pourcentageMarge"
	Enregistrement "nombreProduit" dans le stock
	Vend "nomProduit" pour "montant"
	Soustraction du stock
	Fabrication pour maintient du stock à "quantitéStock" par jour


##FABRICATION ARTICLES :##

	Entreprise fabrique "quantité" de "nomArticle"
	Achète "quantité" de "nomMatière" à "LaMine" pour "montant"
	Achète "nomProduits" à "nomEntreprise"
	Si "nomEntreprise" vend le même produit = concurrent direct donc prix de vente plus cher
	Soustraction de "montant" - "trésorerie"
	Prix de vente = "montant" + "chargesEntreprises" + "marge"
	Enregistrement "nombreProduit" dans le stock
	Vend "nomArticle" pour "montant"
	Soustraction du stock
	Fabrication pour maintient du stock à "quantitéStock" par jour


##QUALITÉ :##

	Attribution du score de qualité à minimum 1 au début. Selon la catégorie du produit et le domaine de l'entreprise (si entreprise de métallurgie vend fil 
	électrique : qualité supérieur, si entreprise de plastique : qualité inférieur)
	Score de qualité augmenté avec la recherche
	Augmentation du score de 0.2 à chaque niveau de recherche
	Augmentation du prix de vente : "prixVente" x "scoreQualité"


##RECHERCHE ET DÉVELOPPEMENT :##

	Entreprise investi "montantInvestissement" pour la recherche et le développement de "nomProduit"
	Déduction de "montantInvestissement" - "trésorerie"
	Augmentation niveau de recherche + 1
	Augmentation du score qualité de 0.2
	Augmentation du prix de vente de "nomProduit"


##EXEMPLE DÉROULEMENT ALGORYTHME :##
 
	1. Choix du produit à fabriquer : "Ordinateurs"
	2. Vérification des matières nécessaires à la fabrication : Écrans, Circuits Imprimés, Fil de cuivre, Verre, Granules plastique, Vis
	3. "Verrutil" et "Heavy Metal" fabriquent "Écrans" et "Circuits Imprimés"
	4. "Fantastic Plastic" et "Heavy Metal" achètent "quantité" de matière à "La Mine" pour la fabrication des écrans et circuits imprimés
	5. Fabrication des écrans et circuits imprimés lorsque toutes les matières sont acheté et en stock
	6. Fabrication des ordinateurs lorsque toutes les pièces nécessaire à la fabrication sont fabriqué et en stock
	7. Ajout des ordinateurs dans le stock des entreprises
	8. "Heavy Metal" et "Verrutil" vendent des ordinateur pour "montant"
	9. Consommateurs achètent
	10. Soustraction du montant acheté par consommateurs du stock des entreprises
	11. Nouvelle fabrication pour maintenir le stock
	



