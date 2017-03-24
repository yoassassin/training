using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace mvc3.micro.music_store.Models
{
    public class Genre
    {
        public string Name { get; set; }
        public int GenreId { get; set; }
        public string Description { get; set; }

        //分类下 很多个 唱片
        public List<Album> Albums { get; set; } //关联其他类的关系

    }
}