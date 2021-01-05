if(screen.width > 768){
    document.getElementById("testimonials").style.display = "none";
    
} else {
    document.getElementById("experience").style.display = "none";
    // document.getElementById("testimonials").style.backgroundColor = "black";    
}


year = new Date().getFullYear()

document.querySelector("#footer p").innerHTML = "© " + year + " Rohan Agarwal. All rights reserved ";