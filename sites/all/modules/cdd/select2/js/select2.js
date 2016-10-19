(function($) {
  Drupal.behaviors.select2 = {
    attach: function (context, settings) {
      $('select:not(.skip-select2)').select2({
        'width': 'resolve'
      });
    }
  };
})(jQuery);
