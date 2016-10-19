<div class="sidebar-wrap">
  <?php if (!empty($sidebar_banner)): ?>
    <?php print $sidebar_banner ?>
  <?php endif; ?>
  <form id="sidebar-search-form">
    <input type="text" class="form-control" placeholder="поиск...">
  </form>
  <div id="sidebar-ajax-search-result" style="display:none;">
    <div class="row">
      <div class="leftcol column">
      </div>
      <div class="rightcol column">
      </div>
    </div>
  </div>
  <?php if (!empty($specializations_tags)): ?>
    <?php print $specializations_tags ?>
  <?php endif; ?>
  <?php if (!empty($sidebar_segments)): ?>
    <?php print $sidebar_segments ?>
  <?php endif; ?>
  <?php if (!empty($sidebar_news)): ?>
    <?php print $sidebar_news ?>
  <?php endif; ?>
  <?php if (!empty($sidebar_tweets)): ?>
    <?php print $sidebar_tweets ?>
  <?php endif; ?>
  <?php if (!empty($sidebar_blog)): ?>
    <?php print $sidebar_blog ?>
  <?php endif; ?>
</div>