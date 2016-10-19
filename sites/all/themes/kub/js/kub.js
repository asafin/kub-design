(function ($) {
    $(document).ready(function () {
        carousel();
        tabHelper();
    });

    var carousel = function () {
        if ($('.view-carousel-block .view-content div.views-row').length > 1) {
            $('.view-carousel-block .view-content').slidesjs({
                width: 750,
                height: 300,
                navigation: {
                    active: false
                },
                pagination: {
                    active: true
                },
                play: {
                    active: false,
                    effect: "fade",
                    interval: 8000,
                    auto: true,
                    pauseOnHover: true,
                    restartDelay: 2500
                }
            });
        }
    };

    var tabHelper = function(){
        $('#promo-tabs .nav li:first-child').addClass('active');
        $('#promo-tabs .tab-content .tab-pane:first-child').addClass('active');
    }

    var equalHeights = function (row, selector) {
        $(row).each(function () {
            var $this = $(this);
            var tallestColumn = 0;
            $this.find(selector).each(function () {
                var currentHeight = $(this).height();
                if (currentHeight > tallestColumn) {
                    tallestColumn = currentHeight;
                }
            });
            $this.find(selector).height(tallestColumn);
        });
    };
})(jQuery);