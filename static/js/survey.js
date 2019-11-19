$(document).ready(function(){
    $('#maximum_quarter').on('change', function(e){
        var id = e.target.value;
        document.getElementById("quarter_value").innerHTML = id;
    });
    $('#maximum_quarter').change();
});

$(document).ready(function(){
    $('#maximum_units').on('change', function(e){
        var id = e.target.value;
        document.getElementById("units_value").innerHTML = id;
    });
    $('#maximum_units').change();
});
