using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvc3.micro.music_store.Models
{
    public class Album
    {
        public string Title { get; set; }
        public int AlbumId { get; set; }
        public int GenreId { get; set; }
        public int ArtistId { get; set; }
        public decimal Price { get; set; }
        public string AlbumArtUrl { get; set; }
        
        
        //唱片下能看到 分类和艺术家
        public Genre Genre { get; set; }
        public Artist Artist { get; set; }
    }
}