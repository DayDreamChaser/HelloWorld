import scrapy

class MeizituItem(scrapy.Item):
    url = scrapy.Field()
    name = scrapy.Field()
    tags = scrapy.Field()
    image_urls = scrapy.Field()
    images = scrapy.Field()
    
BOT_NAME = 'meizitu'

SPIDER_MODULES = ['meizitu.spiders']
NEWSPIDER_MODULE = 'meizitu.spiders'
#载入ImageDownLoadPipeline类
ITEM_PIPELINES = {'meizitu.pipelines.ImageDownloadPipeline': 1}
#图片储存
IMAGES_STORE = '.'